/**
 * This file contains functions that render the game world to the terminal.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "info_messages.h"
#include "input_keys.h"
#include "render.h"
#include "requirements.h"

struct Point {
    int x;
    int y;
};

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
    void renderOutline();
}
