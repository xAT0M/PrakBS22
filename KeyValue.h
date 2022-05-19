//
// Created by Erdinc on 09.05.2022.
//
#ifndef CLION_KEYVALUE_H
#define CLION_KEYVALUE_H

#define MAXSTORE 100


typedef struct KeyValueStore {
    char key[MAXSTORE];
    char value[MAXSTORE];
} kvs;



int put(char* key, char *value, kvs *speicher);
char* get(char* key, kvs *speicher);
int del(char* key, kvs *speicher);




#endif //CLION_KEYVALUE_H





