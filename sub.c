#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "sub.h"
#include "KeyValue.h"
#include <string.h>



void closeProzess(int cfd,int rfd){

    printf("\nVerbindung zum Client wird unterbrochen und Prozess %i beendet", getpid());

    close(cfd); //Client schließen
    close(rfd);
    exit(0); // Prozess beenden
}



int welcherBefehlIstEs(char String[]){

    char get[] = "get";
    char put[] = "put";
    char del[] = "del";
    char quit[] = "QUIT";

    if(strcmp(String,get)==0){
        return 2;

    }else if(strcmp(String,put)==0){
        return 1;

    }else if(strcmp(String,del)==0){
        return 3;

    }else if(strcmp(String,quit)==0){
        return 4;
    }
    return 0;

}


