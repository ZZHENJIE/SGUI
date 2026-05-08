#include "window/main.h"
#include "SDL3/SDL_log.h"
#include "core/application.h"
#include "window/settings.h"

MainWindow::MainWindow() : Window("STimer", 800, 600, SDL_WINDOW_RESIZABLE) {
    addWindow(std::make_unique<SettingsWindow>());
    x = 1.0;
    y = 1.0;
}

void MainWindow::render(SDL_Renderer* renderer) {
    this->x += 0.1;
    this->y += 0.1;
    SDL_FRect rect = SDL_FRect{x, y, 100, 100};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderRect(renderer, &rect);
}

void MainWindow::update(SDL_Event& event) {
    if(event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        SDL_Log("Main");
    }
    if(event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED){
        Application::quit();
    }
}
