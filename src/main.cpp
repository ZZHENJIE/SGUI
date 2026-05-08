#include "window/main.h"
#include "core/application.h"
#include <SDL3/SDL.h>
#include <curl/curl.h>

int main(int argc, char* argv[]){

    SDL_Init(SDL_INIT_VIDEO);

    Application app(std::make_unique<MainWindow>());

    return app.run();
}
