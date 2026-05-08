#pragma once

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_render.h"

class Widget{
private:
    float x, y, width, height;
public:
    Widget(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {}
    virtual ~Widget() = default;
    virtual void update(SDL_Event& event) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    SDL_FRect getRect();
};
