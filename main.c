#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/shm.h>
#include <string.h>

#include "sub.h"
#include "KeyValue.h"

#define ENDLOSSCHLEIFE 1
#define PORT 5688 // Port vom Server

int main()
{

    int rfd; // Rendevouz-Descriptor Server, dient zur Communication
    int cfd; // Verbindungs-Descriptor vom Client, dient nur zum Verbinden

    char string1[BUFSIZ];
    char string2[BUFSIZ];
    char string3[BUFSIZ];
    char output[BUFSIZ];

    FILE *sockstream;

    kvs *speicher = NULL; //Shared Memory vom KeyValueStore

    int shmID = shmget(IPC_PRIVATE, MAXCHAR * sizeof (kvs), IPC_CREAT | 0644); // Segment öffnen mit einer größe von 100 Einträgen
    speicher = (kvs *)shmat(shmID,0,0); // Alle Prozesse an das Segment einbinden
    memset(speicher, 0, MAXCHAR * sizeof (kvs)); // Alle Keys und Values leeren
    shmctl(shmID,IPC_RMID,0); // Segment soll gelöscht werden, falls keiner mehr Verbunden ist

    if (shmID == -1)
    {
        perror("Shared Memory kann nicht angelegt werden");
        exit(-1);
    }


    struct sockaddr_in client; // Daten vom Client
    socklen_t client_len; // Länge des Clients


    // Socket erstellen
    rfd = socket(AF_INET, SOCK_STREAM, 0);
    if (rfd < 0)
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
    if (brt < 0)
    {
        fprintf(stderr, "socket konnte nicht gebunden werden\n");
        exit(-1);
    }


    // Socket wartet bis ein Client sich verbindet
    int lrt = listen(rfd, 5);
    if (lrt < 0)
    {
        fprintf(stderr, "socket konnte nicht listen gesetzt werden\n");
        exit(-1);
    }

    while (ENDLOSSCHLEIFE) {

        cfd = accept(rfd, (struct sockaddr *) &client, &client_len); // Server akzeptiert einen Client

        int pid = fork(); // Ein 2. Prozess entsteht

        if (pid == 0)
        {
            printf("\nVerbindung zum Client %i wurde aufgebaut \xE2\x9C\x93\n", getpid());
        }

        if (pid < 0)
        {
            fprintf(  stderr, "Fehler: es konnte nicht geforkt werden\n\n");
            exit(-1);
        }

        sockstream = fdopen(cfd, "r+"); // r+ = Read & Write

        while(pid == 0)
        {
          memset(output,0,sizeof(output));
          memset(string1,0,sizeof(string1));
          memset(string2, 0, sizeof(string2));
          memset(string3, 0, sizeof(string3));

          fscanf(sockstream, "%s", string1);
            if(BefehlErkenner(string1) > 1)
            {
                fscanf(sockstream, "%s", string2);
                if(BefehlErkenner(string1) == 4)
                {
                    fscanf(sockstream, "%s", string3);
                }
            }
            rewind(sockstream);

            switch (BefehlErkenner(string1))
            {
                case 4:
                    sprintf(output,"\n%s:%s:%s\n\n", string1,string2, string3), put(string2, string3, speicher);
                    write(cfd,output,sizeof(output));
                    break;
                case 3:
                    sprintf(output,"\n%s:%s:%s\n\n", string1,string2, get(string2, speicher));
                    write(cfd,output,sizeof(output));
                    break;
                case 2:
                    sprintf(output,"\n%s:%s:%s\n\n",string1,string2, get(string2, speicher));del(string2, speicher);
                    write(cfd,output,sizeof(output));
                    break;
                case 1:
                    closeProzess(cfd, rfd);shmdt(speicher);
                    break;
                default:
             //        sprintf(output,"\nKein Befehl erkannt\n\n");write(cfd,output,sizeof(output));
                    break;
            }

//            if (bytes_read == 0) {
//                printf("\nVerbindung zum Client unterbrochen %i", getpid());
//                shmdt(speicher);
//                exit(0);
//            }
        }
            close(cfd);
        }
    close(rfd);  // Rendevouz Descriptor schließen
    }
