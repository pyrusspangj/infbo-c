//
// Created by hunte on 3/6/2024.
//

#ifndef INFBOC_STORAGEUNIT_H
#define INFBOC_STORAGEUNIT_H

#include <stdint.h>
#include <stdio.h>
#include <limits.h>

typedef struct {

    char ikey[64][32];
    char fkey[64][32];
    char skey[64][32];
    int ival[64];
    float fval[64];
    char *sval[64];

    uint32_t icrsr;
    uint32_t fcrsr;
    uint32_t scrsr;

} StorageUnit;

void init_su(StorageUnit *su);
void icram(StorageUnit *su, int val, char *key);
void fcram(StorageUnit *su, float val, char *key);
void scram(StorageUnit *su, char *val, char *key);
void free_storage_unit(StorageUnit *su);
int unit_getint(StorageUnit *su, char *key);
float unit_getfloat(StorageUnit *su, char *key);
char* unit_getstr(StorageUnit *su, char *key);
char* unit_getvia_ascii(StorageUnit *su, int ascii);
void load_file(StorageUnit *su, char *fp);
void print_iunit(StorageUnit *su);
void print_funit(StorageUnit *su);
void print_sunit(StorageUnit *su);
void print_unit(StorageUnit *su);

#endif //INFBOC_STORAGEUNIT_H
