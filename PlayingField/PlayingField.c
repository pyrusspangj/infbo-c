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
int get_width(struct PlayingField *first){
    return first->width;
}

int get_height(struct PlayingField *first){
    return first->height;
}

void set_width(struct PlayingField *first, int val){
    first->width = val;
}

void set_height(struct PlayingField *first, int val){
    first->height = val;
}
// getters and setters for pf
//

void draw_red_pixel(HWND hwnd, int x, int y) {
    HDC hdc = GetDC(hwnd);
    SetPixel(hdc, x, y, RGB(255, 0, 0)); // SetPixel to draw a red pixel
    ReleaseDC(hwnd, hdc);
}

void init_game(struct PlayingField *first){
    first->test_value = 0;
    set_height(first, 720);
    set_width(first, 1280);
    first->previous = NULL;
}

void make(struct PlayingField *pf){
    //printf("My playingfield's value is %d!\n", pf->test_value);   // Uncomment and run these lines to debug if your
    //pf->test_value++;                                             // PlayingField is not properly updating.

    pf->previous = pf; // VERY LAST STATEMENT! important!! or else the PlayingField won't be properly updated!
}