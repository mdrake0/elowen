#include <stdbool.h>
#include <sys/ioctl.h>


bool isWindowValid(struct winsize size);
void render();
void renderDimensionError(struct winsize size);
void renderGame(struct winsize size);
