#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "PlayingField/PlayingField.h"
#include "Entities/Player.h"
#include "Assets/StorageUnit.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_COMMAND:
            MessageBox(NULL, "Button Clicked!", "Message", MB_OK);

            // Modify pixel at position (10, 10) when the button is clicked
            draw_red_pixel(hwnd, 10, 10);

            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main() {

    printf("Press any key (ESC to exit):\n");

    struct StorageUnit *su;
    init_su(su);
//    icram(su, 18, "age");
//    fcram(su, 3.7, "gpa");
//    scram(su, "hunter", "name");
//    scram(su, "m", "gender");
//    printf("key age, value: %d\n", unit_getint(su, "age"));
//    printf("key gpa, value: %f\n", unit_getfloat(su, "gpa"));
//    printf("key name, value %s\n", unit_getstr(su, "name"));
//    printf("key gender, value %s\n", unit_getstr(su, "gender"));

    struct PlayingField playing_field;
    init_game(&playing_field);

    struct Player i;
    init_player(&i);

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
                    printf("ESC key pressed. Exiting.\n");
                    return 0;
                }

                inpkey[0] = (char)key;
                asckey = key;

                printf("Key pressed: %c\nKey value pressed:%d\n", inpkey[0], asckey);
            }
        }

        switch(asckey){
            case 65 :
                printf("Moving left\n");
                break;
            case 68 :
                printf("Moving right\n");
                break;
            case 83 :
                printf("Moving down\n");
                break;
            case 87 :
                printf("Moving up\n");
                break;
            case 32 :
                printf("Jumping\n");
                break;
        }

        make(&playing_field);
    }

    // }

    return 0; // just in case ;)
}
