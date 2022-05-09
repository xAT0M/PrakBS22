#include <stdio.h>
#include <stdlib.h>


typedef struct Knoten_ {
    char *key;
    char *value;
    struct Knoten_ *next;
} Knoten;

Knoten *kopf = NULL;


int knotengroesse(){
    return sizeof(Knoten);
}



int put(char* key, char* value)
{

    Knoten *a, *temp;

    a = (Knoten *) malloc(sizeof(Knoten));
    if (kopf == NULL) {
        kopf = a;
        kopf->key = key;
        kopf->value = value;
        kopf->next = NULL;
    } else {
        temp = kopf;
        while (temp->next != NULL) {
            if(temp->key == key){
                temp->value = value;
                temp->next = NULL;
                return 1; //1 = vorhanden, wird überschrieben
            }
            temp = temp->next;
        }
        temp->next = a;
        a->key = key;
        a->value = value;
        a->next = NULL;
        return 0; //0, nicht vorhanden, wird erstellt

    }
}


int get(char* key, char* res){
    Knoten *temp;
    char* t;

    if(kopf == NULL){
        return -1; // -1 = keine keys wurden angelegt
    }
    temp = kopf;

    if(temp->key == key){
        return res; // wird wahrscheinlich nicht gehen
    }

    while(temp->next != NULL){
        if(temp->key == key){
            t = temp->value;
            temp->next = NULL;

            return t;
        }
        temp = temp->next;
    }
    return 0; // 0= key nicht gefunden
}

int del(char* key){
    Knoten *next, *prev;

    if (kopf == NULL){
        return -1; // -1= Liste hat keinen eintrag
    }
    else
    {
        prev = kopf;
        next=kopf->next;
    }
    while(next !=NULL){
        if(next->key == key){
            prev->next = next->next;
            free(next);
            return 0; //0=gefunden und gelöscht
        }
        prev=next;
        next = next->next;
    }
    return -2;//key nicht gefunden
}

