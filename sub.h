#ifndef CLION_SUB_H
#define CLION_SUB_H
#define MAXCHAR 64

void closeProzess(int cfd, int rfd);

int BefehlErkenner(char String[]);

int wievielesubs();

typedef struct subsc {
    long pid;
    char key[MAXCHAR];
} subs;

int subAdd(long pid, char *key, subs *sub, int subcount);

#endif
