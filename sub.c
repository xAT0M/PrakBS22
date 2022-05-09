#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "sub.h"
#include "KeyValue.h"

int stringcompare(char string[], char string1[]) {
    int i = 0;
    while (string[i] != '\0' || string1[i] != '\0') {
        if (string[i] != string1[i]) {
            return 0;

        }
        return 1;
    }
}


void closeProzess(int cfd, int rfd){

    printf("\nVerbindung zum Client wird unterbrochen und Prozess %i beendet", getpid());
    close(cfd); //Client schließen
    close(rfd); //Server schließen, wieso braucht man das?
    exit(0); // Prozess beenden
}

