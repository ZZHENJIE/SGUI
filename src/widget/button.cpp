#include "widget/button.h"

Button::Button(std::string label): Widget(10, 10, 100, 50), label(label) {}

void Button::setOnClick(std::function<void()> callback) {
    onClick = callback;
}

void Button::update(SDL_Event& event){
    if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        SDL_FPoint point = {event.button.x, event.button.y};
        SDL_FRect rect = getRect();
        if (SDL_PointInRectFloat(&point, &rect)) {
            if (onClick) {
                onClick();
            }
        }
    }
}

void Button::render(SDL_Renderer* renderer) {
    SDL_FRect rect = getRect();
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderRect(renderer, &rect);
    SDL_RenderDebugText(renderer, 15, 15, this->label.c_str());
}
