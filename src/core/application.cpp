#include "core/application.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_timer.h"
#include "core/httpclient.h"
#include "curl/curl.h"

Application::~Application(){
    curl_global_cleanup();
    SDL_Quit();
};

int Application::run(){
    bool running = true;
    while (running) {
        SDL_Event event{};
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                running = false;
            }
            this->main_window->_update(event);
        }
        this->main_window->_render();
        HttpClient::instance().poll();
        SDL_Delay(16);
    }
    return 0;
}

void Application::quit() {
    SDL_Event quitEvent{SDL_EVENT_QUIT};
    SDL_PushEvent(&quitEvent);
}
