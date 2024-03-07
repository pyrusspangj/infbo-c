//
// Created by hunte on 3/3/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Player.h"
#include "../Assets/StorageUnit.h"

void init_player(Player *i, StorageUnit *su) {
    i->su = su;
    i->iid_position[0] = unit_getint(su, "PlayerX");
    i->iid_position[1] = unit_getint(su, "PlayerY");
    i->iiid_mode = 0;
    i->act_desc = "IDLE";
}

void mod_player_pos(Player *i){
    char *d = i->act_desc;
    if(strcmp(d, "LEFT") == 0 || strcmp(d, "RIGHT") == 0) {
        set_playerx_viamove(i, d);
    } else if(strcmp(d, "FORWARD") == 0 || strcmp(d, "BACKWARD") == 0){
        set_playery_viamove(i, d);
    } else if(strcmp(d, "INWARD") == 0 || strcmp(d, "OUTWARD") == 0){
        set_playerz_viamove(i, d);
    }
}

void std_input(Player *i, int ord) {
    i->act_desc = unit_getvia_ascii(i->su, ord);
    //printf("Player performing action: %s\n", i->act_desc);
    mod_player_pos(i);
}

void set_playerx_viamove(Player *i, char *move){
    if(strcmp(move, "LEFT") == 0) set_playerx(i, 1, -1);
    else if(strcmp(move, "RIGHT") == 0) set_playerx(i, 1, 1);
    else perror("Invalid movement request in context of x-axis movement.\n");
}

void set_playery_viamove(Player *i, char *move){
    if(strcmp(move, "FORWARD") == 0) set_playery(i, 1, -1);
    else if(strcmp(move, "BACKWARD") == 0) set_playery(i, 1, 1);
    else perror("Invalid movement request in context of y-axis movement.\n");
}

void set_playerz_viamove(Player *i, char *move){
    if(strcmp(move, "INWARD") == 0) set_playerz(i, 1, -1);
    else if(strcmp(move, "OUTWARD") == 0) set_playerz(i, 1, 1);
    else perror("Invalid movement request in context of z-axis movement.\n");
}

void set_playerx(Player *i, int respect, int margin) {
    int* position = (i->iiid_mode) ? i->iiid_position : i->iid_position;
    position[0] = (respect) ? position[0] + margin : margin;
}


void set_playery(Player *i, int respect, int margin){
    int* position = (i->iiid_mode) ? i->iiid_position : i->iid_position;
    position[1] = (respect) ? position[1] + margin : margin;
}

void set_playerz(Player *i, int respect, int margin){
    int* position = i->iiid_position;
    position[2] = (respect) ? position[2] + margin : margin;
}

int get_playerx(Player *i){
    if(i->iiid_mode) return i->iiid_position[0];
    return i->iid_position[0];
}

int get_playery(Player *i){
    if(i->iiid_mode) return i->iiid_position[1];
    return i->iid_position[1];
}

int get_playerz(Player *i){
    return i->iiid_position[2];
}

void Start$P(Player *i, StorageUnit *su){
    init_player(i, su);
}

void Update$P(Player *i){
    i->act_desc = "IDLE";
}

void free_player(Player *i){
    free(i);
}
