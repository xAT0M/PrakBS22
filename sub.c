#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sub.h"
#include <string.h>




void closeProzess(int cfd,int rfd)
{
    printf("\nVerbindung zum Client wird unterbrochen und Prozess %i beendet", getpid());
    close(cfd); //Client schließen
    close(rfd);
    exit(0); // Prozess beenden
}


/* get = 3
 * put = 4
 * del = 2
 * quit = 1
 */


int BefehlErkenner(char String[])
{

    char get[] = "get";
    char put[] = "put";
    char del[] = "del";
    char quit[] = "quit";

    if(strcmp(String,get)==0)
    {
        return 3;

    }else if(strcmp(String,put)==0)
    {
        return 4;

    }else if(strcmp(String,del)==0)
    {
        return 2;

    }else if(strcmp(String,quit)==0)
    {
        return 1;
    }
    return -1;
}



