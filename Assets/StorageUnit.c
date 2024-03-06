//
// Created by hunte on 3/6/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StorageUnit.h"

void init_su(struct StorageUnit *su){
    su->icrsr = 0;
    su->fcrsr = 0;
    su->scrsr = 0;
}

void icram(struct StorageUnit *su, int val, char *key){
    strcpy(su->ikey[su->icrsr], key);
    su->ival[su->icrsr] = val;
    su->icrsr++;
}

void fcram(struct StorageUnit *su, float val, char *key){
    strcpy(su->fkey[su->fcrsr], key);
    su->fval[su->fcrsr] = val;
    su->fcrsr++;
}

void scram(struct StorageUnit *su, char *val, char *key){
    strcpy(su->skey[su->scrsr], key);
    su->sval[su->scrsr] = val;
    su->scrsr++;
}

int unit_getint(struct StorageUnit *su, char *key){
    for(int i=0; i<su->icrsr; ++i)
        if(strcmp(su->ikey[i], key) == 0) return su->ival[i];
    return -1;
}

float unit_getfloat(struct StorageUnit *su, char *key){
    for(int i=0; i<su->fcrsr; ++i)
        if(strcmp(su->fkey[i], key) == 0) return su->fval[i];
    return -2.718281828459045f;
}

char* unit_getstr(struct StorageUnit *su, char *key){
    for(int i=0; i<su->scrsr; ++i)
        if(strcmp(su->skey[i], key) == 0) return su->sval[i];
    return NULL;
}

