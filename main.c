#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/shm.h>
#include <string.h>
#include "sub.h"
#include "KeyValue.h"

#define BUFSIZE 1024 // Größe des Buffers
#define ENDLOSSCHLEIFE 1
#define PORT 5688
#define KeyValue 3



int main() {

    int rfd; // Rendevouz-Descriptor server
    int cfd; // Verbindungs-Descriptor client

    char *befehle[KeyValue];
    memset(befehle,0,sizeof(befehle));
    char *zs;
    char *b = ";";
    int i;



    kvs *speicher = NULL; //Struct mit dem Array drin

    int shmID = shmget(IPC_PRIVATE, MAXSTORE * sizeof (kvs), IPC_CREAT | 0644); // Segment öffnen mit einer größe von 100 kvs
    speicher = (kvs *)shmat(shmID,0,0); // Alle Prozesse an das Segment einbinden
    memset(speicher,0,MAXSTORE * sizeof (kvs)); // Alle Keys und Values auf 0 setzen
    shmctl(shmID,IPC_RMID,0);

    if (shmID == -1) {
        perror("Shared Memory kann nicht angelegt werden");
        exit(-1);
    } // Share Memory fehler


    struct sockaddr_in client; // Socketadresse eines Clients
    socklen_t client_len; // Länge der Client-Daten
    char in[BUFSIZE]; // Daten vom Client an den Server
    memset(in,0,sizeof(in));
    int bytes_read; // Anzahl der Bytes, die der Client geschickt hat


    // Socket erstellen
    rfd = socket(AF_INET, SOCK_STREAM, 0);
    if (rfd < 0) {
        fprintf(stderr, "socket konnte nicht erstellt werden\n");
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


    // Socket lauschen lassen
    int lrt = listen(rfd, 5);
    if (lrt < 0) {
        fprintf(stderr, "socket konnte nicht listen gesetzt werden\n");
        exit(-1);
    }

    while (ENDLOSSCHLEIFE) {


        // Verbindung eines Clients wird entgegengenommen
        cfd = accept(rfd, (struct sockaddr *) &client, &client_len);

        int pid = fork(); // Programm wird dupliziert, Vater und Sohn sind mit Client verbunden

        if (pid < 0) { // Fork ist fehlgeschlagen
            fprintf(  stderr, "NO FORK :(\n");
            exit(-1);
        }

        if (pid == 0) { //Kind geht in die Abfrage rein

            bytes_read = read(cfd, in, BUFSIZE); // Liest Daten vom Client

            while (bytes_read > 0) {  // Solange Daten ankommen, erwartet der Server mehr

                printf("\nString: %s \nwurde von der PID %i empfangen \n", in, getpid());

                zs = strtok(in," ");

                for(i=0;i<KeyValue;i++){
                    befehle[i] = zs;
                    zs = strtok(NULL, " ");
                }

                switch (welcherBefehlIstEs(befehle[0])) {
                    case 1:
                        printf("Der Key: %s \n wurde mit dem Value: %s gespeichert. \n",befehle[1],befehle[2]), put(befehle[1],befehle[2],speicher);
                        write(cfd, befehle[0], BUFSIZE);break;
                    case 2:
                       printf("Für den Key: %s \n wurde der Value: %s gefunden \n",befehle[1],get(befehle[1],speicher));break;
                    case 3:
                        del(befehle[1],speicher); break; //testen
                    case 4:
                        closeProzess(cfd,rfd); shmdt(speicher); break;
                    default:
                        break;
                }




                memset(befehle,0,sizeof(befehle));
                memset(in,0,sizeof(in));

                bytes_read = read(cfd, in, BUFSIZE);

                if (bytes_read == 0) {
                    printf("\nVerbindung zum Client unterbrochen %i", getpid());
                    shmdt(speicher);
                    exit(0);
                }
                if (pid > 0) { //Vater schließt die Verbindung zum Clien
                    close(cfd);

                }
            }

            // Rendevouz Descriptor schließen
            close(rfd);


        }
    }
}
