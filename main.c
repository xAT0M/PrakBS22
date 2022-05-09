#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/shm.h>


#include "sub.h"
#include "KeyValue.h"

#define BUFSIZE 1024 // Größe des Buffers
#define ENDLOSSCHLEIFE 1
#define PORT 5688



//seks
int main() {



    int rfd; // Rendevouz-Descriptor server
    int cfd; // Verbindungs-Descriptor client


    int shmID = shmget(IPC_PRIVATE, knotengroesse(), IPC_CREAT | 0644); //bruh
    if (shmID == -1){
        perror("Shared Memory kann nicht angelegt werden");
        exit(-1);
    }
//    int shared_mem = (int *)shmat(shmID,0,0); //muss zum int, weil es sonst ein char gibt, pointer der adresse

    char closeC[BUFSIZE] = "close"; //Befehle

    struct sockaddr_in client; // Socketadresse eines Clients
    socklen_t client_len; // Länge der Client-Daten
    char in[BUFSIZE]; // Daten vom Client an den Server
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
            fprintf(stderr, "NO FORK :(\n");
            exit(-1);
        }

        if (pid == 0) { //Kind geht in die Abfrage rein
            bytes_read = read(cfd, in, BUFSIZE); // Liest Daten vom Client
            while (bytes_read > 0) {  // Solange Daten ankommen, erwartet der Server mehr

                if (stringcompare(in, closeC)){ //Test
                    closeProzess(cfd,rfd);
                }else {
                    printf("\nString: %swurde von der PID %i empfangen \n", in, getpid());
                    //   write(cfd, in, bytes_read); //Test
                }

                bytes_read = read(cfd, in, BUFSIZE);

                if (bytes_read == 0) {
                    printf("\nVerbindung zum Client unterbrochen %i", getpid());
                    exit(0);
                }
                if (pid > 0) { //Vater schließt die Verbindung zum Client
                    close(cfd);
                }
            }
            // Rendevouz Descriptor schließen
            close(rfd);
        }
    }
}

