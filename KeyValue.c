#include <string.h>
#include "KeyValue.h"

/* put KEY VALUE
 * get KEY
 * del KEY
 */

int c = 0;

int put(char *key, char *value, kvs *speicher) {
    for (int i = 0; i < MAXCHAR; i++) {
        if (strcmp(speicher[i].key, key) == 0) {
            strcpy(speicher[i].value, value);
            return 1;
        }
    }
    strcpy(speicher[c].key, key);
    strcpy(speicher[c].value, value);
    c++;
    return 0;
}


char *get(char *key, kvs *speicher) {
    for (int i = 0; i < MAXCHAR; i++) {
        if (strcmp(speicher[i].key, key) == 0) {
            return speicher[i].value;
        }
    }
    return "Key_nicht_im_Store";
}

int del(char *key, kvs *speicher) {
    int i;
    for (i = 0; i < MAXCHAR; i++) {
        if (strcmp(speicher[i].key, key) == 0) {
            break;
        }
    }
    while (i < MAXCHAR) {
        strcpy(speicher[i].key, speicher[i + 1].key);
        strcpy(speicher[i].value, speicher[i + 1].key);
        i++;
    }
    c--;
    return 0;
}


