#pragma once

#include "core/window.h"

class SettingsWindow : public Window {
public:
    int ok_count = 0;
    SettingsWindow();
    ~SettingsWindow() = default;
    void render(SDL_Renderer* renderer) override;
    void update(SDL_Event& event) override;
};
