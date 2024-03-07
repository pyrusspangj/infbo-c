#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "PlayingField/PlayingField.h"
#include "Entities/Player.h"
#include "Assets/StorageUnit.h"

#define MULTI 4

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_COMMAND:
            MessageBox(NULL, "Button Clicked!", "Message", MB_OK);

            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main() {

    printf("Press any key (ESC to exit):\n");

    StorageUnit *su = (StorageUnit*)malloc(sizeof(StorageUnit));
    init_su(su);
    load_file(su, "def.txt");
    load_file(su, "asciibinds.txt");

    Player *i = (Player*)malloc(sizeof(Player));
    Start$P(i, su);

    PlayingField playing_field;
    init_game(&playing_field, su, i);

    //print_unit(su);

    // {

    const char CLASS_NAME[] = "infbo:c";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
            0,                        // Optional window styles
            CLASS_NAME,               // Window class
            "infbo:c",        // Window text
            WS_OVERLAPPEDWINDOW,      // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, get_width(&playing_field), get_height(&playing_field),

            NULL,        // Parent window
            NULL,        // Menu
            GetModuleHandle(NULL),  // Instance handle
            NULL         // Additional application data
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);


    while (1) {

        char inpkey[3] = "";
        int asckey = -1;

        MSG msg;
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        for (int key = 0; key <= 255; ++key) {
            if (GetAsyncKeyState(key) & 0x8000) {
                if (key == VK_ESCAPE) {
                    free_storage_unit(su);
                    free_player(i);
                    return 0;
                }

                inpkey[0] = (char)key;

                //printf("Key pressed: %c\nKey value pressed:%d\n", inpkey[0], asckey);
                std_input(i, key);
            }
        }

        Update$PF(&playing_field, &hwnd);

        Update$P(i);  // final Player update
    }

    // }

    free_storage_unit(su);
    free_player(i);
    return 0; // just in case ;)
}
