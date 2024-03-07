//
// Created by hunte on 3/3/2024.
//

#ifndef INFBOC_PLAYINGFIELD_H
#define INFBOC_PLAYINGFIELD_H

#include "windows.h"
#include "../Assets/StorageUnit.h"
#include "../Entities/Player.h"

#define MULTI 4

typedef struct {

    struct PlayingField *previous;
    int width, height;
    HWND hwnd;

    Player *player;

    StorageUnit *su;

} PlayingField;

int get_width(PlayingField *first);
int get_height(PlayingField *first);
void set_width(PlayingField *first, int val);
void set_height(PlayingField *first, int val);

void draw_red_pixel(HWND *hwnd, int x, int y);
void init_game(PlayingField *first, StorageUnit *su, Player *i);
void make(PlayingField *pf);

// Player Interaction
void move(Player *p, HWND *hwnd);
void Update$PF(PlayingField *pf, HWND *hwnd);

#endif //INFBOC_PLAYINGFIELD_H
