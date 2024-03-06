//
// Created by hunte on 3/3/2024.
//

#include "windows.h"

#ifndef INFBOC_PLAYINGFIELD_H
#define INFBOC_PLAYINGFIELD_H

struct PlayingField {

    int test_value;
    struct PlayingField *previous;
    int width, height;

};

int get_width(struct PlayingField *first);
int get_height(struct PlayingField *first);
void set_width(struct PlayingField *first, int val);
void set_height(struct PlayingField *first, int val);

void draw_red_pixel(HWND hwnd, int x, int y);
void init_game(struct PlayingField *first);
void make(struct PlayingField *pf);

#endif //INFBOC_PLAYINGFIELD_H
