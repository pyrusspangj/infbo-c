//
// Created by hunte on 3/6/2024.
//

#ifndef INFBOC_STORAGEUNIT_H
#define INFBOC_STORAGEUNIT_H

#include <stdint.h>
#include <stdio.h>
#include <limits.h>

struct StorageUnit {

    char ikey[64][32];
    char fkey[64][32];
    char skey[64][32];
    int ival[64];
    float fval[64];
    char *sval[64];

    uint32_t icrsr;
    uint32_t fcrsr;
    uint32_t scrsr;

};

void init_su(struct StorageUnit *su);
void icram(struct StorageUnit *su, int val, char *key);
void fcram(struct StorageUnit *su, float val, char *key);
void scram(struct StorageUnit *su, char *val, char *key);
int unit_getint(struct StorageUnit *su, char *key);
float unit_getfloat(struct StorageUnit *su, char *key);
char* unit_getstr(struct StorageUnit *su, char *key);

#endif //INFBOC_STORAGEUNIT_H
