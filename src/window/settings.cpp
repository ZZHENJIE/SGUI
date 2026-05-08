#include "window/settings.h"
#include "SDL3/SDL_log.h"
#include "core/httpclient.h"
#include "widget/button.h"

SettingsWindow::SettingsWindow() : Window("Settings", 400, 300, SDL_WINDOW_RESIZABLE) {
    auto button = std::make_unique<Button>("Test");
    button->setOnClick([this]() {
        auto res = HttpClient::instance().get("https://zzhenjie.github.io/JieBook/", [this](Response res) {
            if(res.code == 200){
                this->ok_count+=1;
            }
            SDL_Log("success.");
        });
        SDL_Log("Ok Count: %d",this->ok_count);
        SDL_Log("Send waiting ...");
    });
    addWidget(std::move(button));
}

void SettingsWindow::render(SDL_Renderer* renderer) {

}
void SettingsWindow::update(SDL_Event& event) {

}
