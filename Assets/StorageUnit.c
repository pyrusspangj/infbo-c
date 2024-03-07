//
// Created by hunte on 3/6/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "StorageUnit.h"

void init_su(StorageUnit *su){
    su->icrsr = 0;
    su->fcrsr = 0;
    su->scrsr = 0;
}

void icram(StorageUnit *su, int val, char *key){
    strcpy(su->ikey[su->icrsr], key);
    su->ival[su->icrsr] = val;
    su->icrsr++;
}

void fcram(StorageUnit *su, float val, char *key){
    strcpy(su->fkey[su->fcrsr], key);
    su->fval[su->fcrsr] = val;
    su->fcrsr++;
}

void scram(StorageUnit *su, char *val, char *key) {
    su->sval[su->scrsr] = malloc(strlen(val) + 1);
    if (su->sval[su->scrsr] != NULL) {
        strcpy(su->skey[su->scrsr], key);
        strcpy(su->sval[su->scrsr], val);
        su->scrsr++;
    } else {
        perror("Failed to allocate memory for string.");
    }
}

void free_storage_unit(StorageUnit *su) {
    for (int i = 0; i < su->scrsr; ++i) {
        free(su->sval[i]);
    }
}

int unit_getint(StorageUnit *su, char *key){
    for(int i=0; i<su->icrsr; ++i)
        if(strcmp(su->ikey[i], key) == 0) return su->ival[i];
    return -1;
}

float unit_getfloat(StorageUnit *su, char *key){
    for(int i=0; i<su->fcrsr; ++i)
        if(strcmp(su->fkey[i], key) == 0) return su->fval[i];
    return -2.718281828459045f;
}

char* unit_getstr(StorageUnit *su, char *key){
    for(int i=0; i<su->scrsr; ++i)
        if(strcmp(su->skey[i], key) == 0) return su->sval[i];
    return NULL;
}

char* unit_getvia_ascii(StorageUnit *su, int ascii){
    char asckey[3];
    itoa(ascii, asckey, 10);
    return unit_getstr(su, asckey);
}

void load_file(StorageUnit *su, char *fp) {
    char *key = (char*)malloc(32);
    char type;
    char *middlebuffer = (char*)malloc(32);
    int *ivalp = (int*)malloc(sizeof(int));
    float *fvalp = (float*)malloc(sizeof(float));

    FILE *file = fopen(fp, "r");

    if (file != NULL) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {

            if(buffer[0] == '#') continue;

            if (buffer[0] == '\n' || buffer[0] == '\0') {
                break;
            }

            if (sscanf(buffer, "%49[^:]:%c=%s", key, &type, middlebuffer) == 3) {
                switch(type){
                    case 'i':
                        *ivalp = atoi(middlebuffer);
                        icram(su, *ivalp, key);
                        break;
                    case 'f' :
                        *fvalp = atof(middlebuffer);
                        fcram(su, *fvalp, key);
                        break;
                    case 's' :
                        scram(su, middlebuffer, key);
                        break;
                    default :
                        perror("Invalid type operand or missing type operand.");
                }
            }

        }
        fclose(file);
    } else {
        perror("Failed to open the file.");
    }

    free(key);
    free(middlebuffer);
    free(ivalp);
    free(fvalp);

}

void print_iunit(StorageUnit *su){
    for(int i=0; i<su->icrsr; ++i){
        printf("INT Key: %s, INT Value: %d\n", su->ikey[i], su->ival[i]);
    }
}

void print_funit(StorageUnit *su){
    for(int i=0; i<su->fcrsr; ++i){
        printf("FLT Key: %s, FLT Value: %f\n", su->fkey[i], su->fval[i]);
    }
}

void print_sunit(StorageUnit *su){
    for(int i=0; i<su->scrsr; ++i){
        printf("STR Key: %s, STR Value: %s\n", su->skey[i], su->sval[i]);
    }
}

void print_unit(StorageUnit *su){
    print_iunit(su);
    print_funit(su);
    print_sunit(su);
}
