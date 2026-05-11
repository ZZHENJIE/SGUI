#include "core/window.h"
#include "imgui/imgui.h"
#include <SDL3/SDL_log.h>

Window::Window() : open(false) {

}

Window::~Window() {

}

void Window::_Render(nlohmann::json &settings) {
    if(this->open){
        ImGui::Begin(this->WindowLabel(), &this->open);
        this->Render(settings);
        ImGui::End();
    }
}

void Window::OpenInit() {}

void Window::CloseRelease() {}

bool Window::IsOpen() {
    return this->open;
}

void Window::Open() {
    this->OpenInit();
    this->open = true;
}

void Window::Close() {
    this->CloseRelease();
    this->open = false;
}
