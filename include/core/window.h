#pragma once

#include "SDL3/SDL_video.h"
#include "SDL3/SDL_render.h"
#include "widget.h"
#include <memory>
#include <vector>

class Window{
    friend class Application;
private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_ptr;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_ptr;
    SDL_WindowID window_id;
    std::vector<std::unique_ptr<Widget>> widgets;
    std::vector<std::unique_ptr<Window>> windows;
private:
    void _render();
    void _update(SDL_Event& event);
public:
    Window(const char *title, int w, int h, SDL_WindowFlags flags);
    virtual ~Window() = default;
    template<typename T>
    void addWidget(std::unique_ptr<T> widget){
        widgets.push_back(std::move(widget));
    }

    template<typename T>
    void addWindow(std::unique_ptr<T> window){
        windows.push_back(std::move(window));
    }
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void update(SDL_Event& event) = 0;
};
