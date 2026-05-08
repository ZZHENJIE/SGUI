#include "window/settings.h"
#include "SDL3/SDL_log.h"
#include "widget/button.h"

SettingsWindow::SettingsWindow() : Window("Settings", 400, 300, SDL_WINDOW_RESIZABLE) {
    auto button = std::make_unique<Button>("Test");
    button->setOnClick([this]() {
        SDL_Log("Button clicked.");
    });
    addWidget(std::move(button));
}

void SettingsWindow::render(SDL_Renderer* renderer) {

}
void SettingsWindow::update(SDL_Event& event) {

}
