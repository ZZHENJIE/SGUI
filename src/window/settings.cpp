#include "window/settings.h"
#include "imgui/imgui.h"

Settings::Settings() {

}

Settings::~Settings() {

}

const char * Settings::WindowLabel() {
    return "Settings";
}

void Settings::LoadConfig(nlohmann::json & json) {
    if(json["open"]){
        this->Open();
    }
}

void Settings::SaveConfig(nlohmann::json & json) {
    json["open"] = this->IsOpen();
}

void Settings::Render(nlohmann::json &settings) {
    auto test = settings["test"].get<std::string>();
    ImGui::Text("%s",test.c_str());
}
