#include <stdio.h>

#include "input_keys.h"
#include "render.h"

int main() {
    char c;
    while ((c = getchar()) && c != QUIT_KEY) {
        printf("enter 'q' to quit\n");
        render();
    }
}
