//
// Created by hunte on 3/3/2024.
//

#include "PlayingField.h"
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

// playingfield should essentially be static?? there should only be one, but screw it you could make more if you want.

//
// getters and setters for pf
int get_width(PlayingField *first){
    return first->width;
}

int get_height(PlayingField *first){
    return first->height;
}

void set_width(PlayingField *first, int val){
    first->width = val;
}

void set_height(PlayingField *first, int val){
    first->height = val;
}
// getters and setters for pf
//

void draw_red_pixel(HWND *hwnd, int x, int y) {
    HDC hdc = GetDC(*hwnd);
    SetPixel(hdc, x, y, RGB(255, 0, 0)); // SetPixel to draw a red pixel
    printf("Drawing pixel at %d, %d\n", x, y);
    ReleaseDC(*hwnd, hdc);
}

void init_game(PlayingField *first, StorageUnit *su, Player *i){
    set_height(first, 720);
    set_width(first, 1280);
    first->su = su;
    first->previous = NULL;
    first->player = i;

}

void make(PlayingField *pf){
    //printf("My playingfield's value is %d!\n", pf->test_value);   // Uncomment and run these lines to debug if your
    //pf->test_value++;                                             // PlayingField is not properly updating.

    //pf->previous = (struct PlayingField *) pf; // VERY LAST STATEMENT! important!! or else the PlayingField won't be properly updated!
}

void move(Player *i, HWND *hwnd){
    //printf("Method called\n");
    if (i == NULL || i->act_desc == NULL) {
        return;
    }
    //printf("player not null and players action description not null\n");
    //printf("Player's action description: %s\nd", i->act_desc);
    if(strcmp(i->act_desc, "IDLE") == 0) {
        return;
    }
    //printf("players action is not idle\n");

    //printf("Make it here\n");

    draw_red_pixel(hwnd, get_playerx(i), get_playery(i));
}


void Update$PF(PlayingField *pf, HWND *hwnd){
    pf->hwnd = *hwnd;

    move(pf->player, hwnd);

    make(pf);
}