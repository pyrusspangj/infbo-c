#ifndef INFBOC_PLAYER_H
#define INFBOC_PLAYER_H

#include "../Assets/StorageUnit.h"

typedef struct {

    int iiid_mode;
    int iid_position[2];
    int iiid_position[3];

    char *act_desc;

    StorageUnit *su;

} Player;

void init_player(Player *i, StorageUnit *su);
void mod_player_pos(Player *i);
void std_input(Player *i, int ord);

void set_playerx_viamove(Player *i, char *move);
void set_playery_viamove(Player *i, char *move);
void set_playerz_viamove(Player *i, char *move);
void set_playerx(Player *i, int respect, int margin);
void set_playery(Player *i, int respect, int margin);
void set_playerz(Player *i, int respect, int margin);
int get_playerx(Player *i);
int get_playery(Player *i);
int get_playerz(Player *i);

void Start$P(Player *i, StorageUnit *su);
void Update$P(Player *i);

void free_player(Player *i);

#endif //INFBOC_PLAYER_H
