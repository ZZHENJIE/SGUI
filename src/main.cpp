#include "window/main.h"
#include "core/application.h"
#include <SDL3/SDL.h>
#include <curl/curl.h>

int main(int argc, char* argv[]){
    SDL_Init(SDL_INIT_VIDEO);
    curl_global_init(CURL_GLOBAL_DEFAULT);

    Application app(std::make_unique<MainWindow>());

    int ret = app.run();
    curl_global_cleanup();
    SDL_Quit();
    return ret;
}
