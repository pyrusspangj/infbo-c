//
// Created by hunte on 3/4/2024.
//

#ifndef INFBOC_PLAYER_H
#define INFBOC_PLAYER_H

struct Player {

    int walking;
    int iiid_mode;
    int iid_position[2];
    int iiid_position[3];

};

void init_player(struct Player *i);

#endif //INFBOC_PLAYER_H
