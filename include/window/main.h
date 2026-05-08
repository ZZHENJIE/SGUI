#pragma once

#include "core/window.h"

class MainWindow : public Window {
private:
    float x,y;
public:
    MainWindow();
    ~MainWindow() = default;
    void render(SDL_Renderer* renderer) override;
    void update(SDL_Event& event) override;
};
