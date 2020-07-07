#ifndef RENDER_H
#define RENDER_H

#include <stdbool.h>
#include <sys/ioctl.h>

struct Point;

struct Point getTopLeft(struct winsize size);
bool isWindowValid(struct winsize size);
void render();
void renderDimensionError(struct winsize size);
void renderGame(struct Point pos);
void renderOutline();

#endif