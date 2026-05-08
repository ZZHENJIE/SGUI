#include "SDL3/SDL_video.h"
#include "SDL3/SDL_render.h"
#include "core/window.h"
#include <memory>
#include <vector>

void Window::_render(){
    for (auto &widget : widgets){
        widget->render(this->renderer_ptr.get());
    }
    for (auto &window : windows){
        window->_render();
    }
    this->render(this->renderer_ptr.get());
    SDL_RenderPresent(this->renderer_ptr.get());
}

void Window::_update(SDL_Event& event){
    SDL_WindowID event_window_id = event.window.windowID;
    if(event_window_id == this->window_id){
        for (auto &widget : widgets){
            widget->update(event);
        }
        this->update(event);
    }else{
        for (auto &window : windows){
            if(event_window_id == window->window_id){
                window->_update(event);
            }
        }
    }
}

Window::Window(const char *title, int w, int h, SDL_WindowFlags flags)
    : window_ptr(SDL_CreateWindow(title, w, h, flags), SDL_DestroyWindow),
        renderer_ptr(SDL_CreateRenderer(window_ptr.get(), nullptr), SDL_DestroyRenderer) {
    window_id = SDL_GetWindowID(window_ptr.get());
}
