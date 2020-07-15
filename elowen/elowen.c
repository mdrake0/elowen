#include <curses.h>
#include <stdio.h>

#include "render.h"

int main() {
    // Init curses
    initscr();
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);

    // Game loop
    while (true) {
        render();
    }
}
