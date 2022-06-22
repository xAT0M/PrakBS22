#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/ipc.h>

#include <sys/msg.h>


#include "sub.h"
#include "KeyValue.h"

#define ENDLOSSCHLEIFE 1
#define PORT 5688 // Port vom Server

void putB();

void getB();

void delB();

void subProzess(long pid);

int anybodySub(char *key, char *value, subs *sub);

int rfd; // Rendevouz-Descriptor Server, dient zur Communication
int cfd; // Verbindungs-Descriptor vom Client, dient nur zum Verbinden
int msgID;

char string1[BUFSIZ]; //Input 1 - 3
char string2[BUFSIZ];
char string3[BUFSIZ];
char output[BUFSIZ]; //Telnet Output
char busy[BUFSIZ] = "\nDer Store wird von einem anderen Client genutzt\n\n"; //exclusive Transaktion

int *transaktion = 0; //exklusiver Zugriff auf den Store
kvs *speicher = NULL; //Shared Memory Store
subs *sub = NULL;
int *subsCount = 0;


int main() {
    int temp;
    msgID = msgget(IPC_PRIVATE, IPC_CREAT | 0644);

    FILE *sockstream; //verbesserter Input

    int shmID = shmget(IPC_PRIVATE, MAXCHAR * sizeof(kvs),
                       IPC_CREAT | 0644); //Segment öffnen mit einer größe von 100 Einträgen
    int subsID = shmget(IPC_PRIVATE, MAXCHAR * sizeof(subs), IPC_CREAT | 0644);
    int transakID = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0644); //Segment öffnen für die Transaktionen
    int subsCountID = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0644);

    transaktion = (int *) shmat(transakID, 0, 0); //Prozess an die Transaktion binden
    speicher = (kvs *) shmat(shmID, 0, 0); // Alle Prozesse an das Segment einbinden
    subsCount = (int *) shmat(subsCountID, 0, 0);
    sub = (subs *) shmat(subsID, 0, 0);

    memset(speicher, 0, MAXCHAR * sizeof(kvs)); // Alle Keys und Values leeren
    memset(sub, 0, MAXCHAR * sizeof(subs));
    memset(transaktion, 0, sizeof(int));
    memset(subsCount, 0, sizeof(int));

    shmctl(shmID, IPC_RMID, 0); //Segment wird gelöscht , falls keiner mehr Verbunden ist
    shmctl(transakID, IPC_RMID, 0);// ''
    shmctl(subsID, IPC_RMID, 0);
    shmctl(subsCountID, IPC_RMID, 0);

    if (shmID == -1) //Shared Memory check
    {
        perror("Shared Memory kann nicht angelegt werden");
        exit(-1);
    }
    if (transakID == -1) {
        perror("Transaktion kann nicht angelegt werden");
        exit(-1);
    }
    if (subsID == -1) {
        perror("Subs kann nicht angelegt werden");
        exit(-1);
    }

    struct sockaddr_in client; // Daten vom Client
    socklen_t client_len; // Länge des Clients


    // Socket erstellen
    rfd = socket(AF_INET, SOCK_STREAM, 0);
    if (rfd < 0) //Socket check
    {
        fprintf(stderr, "\nFehler: socket konnte nicht erstellt werden\n");
        exit(-1);
    }


    // Socket Optionen setzen für schnelles wiederholtes Binden der Adresse
    int option = 1;
    setsockopt(rfd, SOL_SOCKET, SO_REUSEADDR, (const void *) &option, sizeof(int));


    // Socket binden
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    int brt = bind(rfd, (struct sockaddr *) &server, sizeof(server));
    if (brt < 0) {
        fprintf(stderr, "socket konnte nicht gebunden werden\n");
        exit(-1);
    }


    // Socket wartet bis ein Client sich verbindet
    int lrt = listen(rfd, 5);
    if (lrt < 0) {
        fprintf(stderr, "socket konnte nicht listen gesetzt werden\n");
        exit(-1);
    }

    while (ENDLOSSCHLEIFE) {

        cfd = accept(rfd, (struct sockaddr *) &client, &client_len); // Server akzeptiert einen Client

        int pid = fork(); // Ein 2. Prozess entsteht

        if (pid == 0) {
            long mainPid = getpid();
            printf("\nDer SubProcess bekommt den Key %li \xE2\x9C\x93\n", mainPid);

            int pid2 = fork();
            if (pid2 == 0) {
                subProzess(mainPid);
            }
            printf("\nVerbindung zum Client %i wurde aufgebaut \xE2\x9C\x93\n", getpid());
        }


        if (pid < 0) {
            fprintf(stderr, "Fehler: es konnte nicht geforkt werden\n\n");
            exit(-1);
        }

        sockstream = fdopen(cfd, "r+"); // r+ = Read & Write | verbesserter Input

        while (pid == 0) {

            memset(output, 0, sizeof(output)); //Inhalt der Strings leeren um fehler zu vorzubeugen
            memset(string1, 0, sizeof(string1));
            memset(string2, 0, sizeof(string2));
            memset(string3, 0, sizeof(string3));

            fscanf(sockstream, "%s",
                   string1); //Befehle erkennen um festzustellen wie viele Inputs gelesen werden müssen
            if (BefehlErkenner(string1) > 2) {
                fscanf(sockstream, "%s", string2);
                if (BefehlErkenner(string1) > 5) {
                    fscanf(sockstream, "%s", string3);
                }
            }
            rewind(sockstream); //file pointer an den Anfang des Files setzen

            if (BefehlErkenner(string1) == 2 && *transaktion == getpid()) { //transaktion beenden
                *transaktion = 0;
            }

            if ((BefehlErkenner(string1) == 0) && *transaktion == 0) { //transaktion beginnen
                *transaktion = getpid();
            }

            if ((*transaktion == getpid()) || (*transaktion == 0) || (BefehlErkenner(string1) == 1)) {
                switch (BefehlErkenner(string1)) {
                    case 6: //put KEY VALUE
                        putB();
                        break;
                    case 5: //sub KEY
                        temp = *subsCount;
                        *subsCount = subAdd((long) getpid(), string2, sub, temp);
                        break;
                    case 4: //get KEY
                        getB();
                        break;
                    case 3: //del key
                        delB();
                        break;
                    case 1: //quit
                        if (*transaktion == getpid()) { *transaktion = 0; }
                        closeProzess(cfd, rfd);
                        shmdt(speicher);
                        shmdt(transaktion);
                        break;
                    default:
                        break;
                }
            } else {
                write(cfd, busy, sizeof(busy));
            }

        }
        close(cfd);
    }
}


void putB() {
    anybodySub(string2, string3, sub);
    sprintf(output, "\n%s:%s:%s\n\n", string1, string2, string3), put(string2, string3, speicher);
    write(cfd, output, sizeof(output));
}

void getB() {
    sprintf(output, "\n%s:%s:%s\n\n", string1, string2, get(string2, speicher));
    write(cfd, output, sizeof(output));

}

void delB() {
    sprintf(output, "\n%s:%s:%s\n\n", string1, string2, get(string2, speicher));
    del(string2, speicher);
    write(cfd, output, sizeof(output));
}

void subProzess(long pid) {
    subs sub2;

    memset(sub2.key, 0, sizeof(sub2.key));
    while (ENDLOSSCHLEIFE) {
        while (msgrcv(msgID, (void *) &sub2, sizeof(sub2.key), pid, MSG_NOERROR | IPC_NOWAIT) < 0);
        write(cfd, sub2.key, sizeof(sub2.key));
        memset(sub2.key, 0, sizeof(sub2.key));
    }

}

int anybodySub(char *key, char *value, subs *subc) {
    for (int i = 0; i < *subsCount; i++) {

        if (strcmp(subc[i].key, key) == 0) {
            subs sub1;
            sub1.pid = subc[i].pid;
            memset(sub1.key, 0, sizeof(sub1.key));
            sprintf(sub1.key, "\n Neuer PUB: %s --> %s\n\n", key, value);
            msgsnd(msgID, (void *) &sub1, sizeof(sub1.key), IPC_NOWAIT);

        }

    }
    return 1;
}

