#include "window/screener.h"
#include "imgui/imgui.h"
#include <cstring>
#include <string>

Screener::Screener() {

}

Screener::~Screener() {

}

const char * Screener::WindowLabel() {
    return "Screener";
}

void Screener::LoadConfig(nlohmann::json & json) {
    if(json["open"]){
        this->Open();
    }
}

void Screener::SaveConfig(nlohmann::json & json) {
    json["open"] = this->IsOpen();
}

void Screener::Render(nlohmann::json &settings) {
    std::string test = settings["test"].get<std::string>();
    char buffer[256];
    std::strncpy(buffer, test.c_str(), sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    if (ImGui::InputText("Test", buffer, sizeof(buffer))) {
        settings["test"] = buffer;
    }
}
