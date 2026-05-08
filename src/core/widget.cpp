#include "core/widget.h"

SDL_FRect Widget::getRect() {
    return {x, y, width, height};
}
