/**
 * This file contains functions that render the game world to the terminal.
 */
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "info_messages.h"
#include "input_keys.h"
#include "render.h"
#include "requirements.h"
#include "runes.h"

struct Point {
    int x;
    int y;
};

// Returns top left position of game window based on terminal size.
struct Point getTopLeft(struct winsize size) {
    struct Point pos;
    pos.x = 0;
    pos.y = 0;
    return pos;
}

// Checks current terminal size against requirements.
bool isWindowValid(struct winsize size) {
    return size.ws_col >= MIN_TERMINAL_WIDTH 
        && size.ws_row >= MIN_TERMINAL_HEIGHT;
}

// Renders the game (or the appropriate error message) to the terminal.
void render() {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    bool validWindowSize = isWindowValid(size);

    if (!validWindowSize) {
        renderDimensionError(size);
    } else {
        struct Point topLeft = getTopLeft(size);
        renderGame(topLeft);
    }
}

// Renders screen-dimension error.
void renderDimensionError(struct winsize size) {
    printf("terminal window must be at least %d columns wide and %d rows tall "
                "to get the Elowen experience\n", 
           MIN_TERMINAL_WIDTH, 
           MIN_TERMINAL_HEIGHT);
    printf("your window is %d columns wide and %d rows tall\n", 
           size.ws_col,
           size.ws_row);    
}

// Renders the game in an 80x24 rectangle with a top-left position of `pos`.
void renderGame(struct Point pos) {
    renderOutline(pos);
    refresh();
}

// Draws an outline around the play area
void renderOutline(struct Point pos) {
    int upperX = pos.x+MIN_TERMINAL_WIDTH;
    int upperY = pos.y+MIN_TERMINAL_HEIGHT;

    for (int i = pos.y; i < upperY; ++i) {
        for (int j = pos.x; j < upperX; ++j) {
            if (i == pos.y || i == upperY-1 || j == pos.x || j == upperX-1) {
                mvaddch(i, j, BORDER_RUNE);
            }
        }
    }
}
