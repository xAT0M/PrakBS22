#ifndef CLION_KEYVALUE_H
#define CLION_KEYVALUE_H

#define MAXCHAR 64


typedef struct KeyValueStore {
    char key[MAXCHAR];
    char value[MAXCHAR];
} kvs;


int put(char *key, char *value, kvs *speicher);

char *get(char *key, kvs *speicher);

int del(char *key, kvs *speicher);

int search(char *key, kvs *speicher);


#endif //CLION_KEYVALUE_H
