#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sub.h"
#include <string.h>


void closeProzess(int cfd, int rfd) {
    printf("\nVerbindung zum Client wird unterbrochen und Prozess %i beendet", getpid());
    close(cfd); //Client schließen
    close(rfd);
    exit(0); // Prozess beenden
}

/*
 * put = 6
 * sub = 5
 * get = 4
 * del = 3
 * end = 2
 * quit = 1
 * beg = 0
 */


int BefehlErkenner(char String[]) {
    char beg[] = "beg";
    char end[] = "end";
    char get[] = "get";
    char put[] = "put";
    char del[] = "del";
    char quit[] = "quit";
    char sub[] = "sub";

    if (strcmp(String, sub) == 0) {
        return 5;
    }
    if (strcmp(String, beg) == 0) {
        return 0;
    }
    if (strcmp(String, end) == 0) {
        return 2;
    }

    if (strcmp(String, get) == 0) {
        return 4;

    } else if (strcmp(String, put) == 0) {
        return 6;

    } else if (strcmp(String, del) == 0) {
        return 3;

    } else if (strcmp(String, quit) == 0) {
        return 1;
    }
    return -1;
}

int z = 0;

int subAdd(long pid, char *key, subs *sub, int subcount) {

//    for(int i = 0; i < MAXCHAR; i++)
//    {
//        if(strcmp(sub[i].key,key)==0)   // keine doppelten subs von einem Client
//        {
//
//            if(sub[i].pid == pid)
//                    return 1;
//                }
//            }
    printf("\nSubscriber davor:  %i\n", subcount);
    strcpy(sub[subcount].key, key);
    sub[subcount].pid = pid;
    printf("\nsubAdd() speichert den Sub %s für die PID %li\n\n", sub[z].key, sub[z].pid);
    subcount++;
    printf("\nSubscriber danach: %i\n", subcount);
    return subcount;

}

int wievielesubs() {
    return z;
}





