#include "core/application.h"
#include "imgui/imgui.h"
#include "window/screener.h"
#include "window/settings.h"
#include <SDL3/SDL_log.h>
#include <cstddef>
#include <fstream>

nlohmann::json config_load(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::ifstream default_file("./default.json");
        if (default_file.is_open()) {
            try {
                nlohmann::json j;
                default_file >> j;
                return j;
            } catch (...) {}
        }
        return nlohmann::json::object();
    }
    try {
        nlohmann::json j;
        file >> j;
        return j;
    } catch (...) {
        return nlohmann::json::object();
    }
}

void config_save(const std::string& path, const nlohmann::json& j) {
    std::ofstream file(path);
    file << j.dump(2);
}

Application::Application(){
    this->config = config_load("./config.json");
    this->windows = std::unordered_map<std::string, std::unique_ptr<Window>>();
    this->initWindows();
}

void Application::initWindows(){
    this->addWindow("Tool/Settings", std::make_unique<Settings>());
    this->addWindow("Tool/Screener", std::make_unique<Screener>());

    for (auto& window_config : this->config["Windows"]) {
        auto label = window_config["label"].get<std::string>();
        this->windows.at(label)->LoadConfig(window_config);
    }
}

Application::~Application(){
    for (auto& window_config : this->config["Windows"]) {
        auto label = window_config["label"].get<std::string>();
        this->windows.at(label)->SaveConfig(window_config);
    }
    config_save("./config.json", this->config);
}

void Application::render(){
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Tool"))
        {
            if (ImGui::MenuItem("Settings", nullptr)) {
                this->windows["Tool/Settings"]->Open();
            }

            if (ImGui::MenuItem("Screener", nullptr)) {
                this->windows["Tool/Screener"]->Open();
            }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", nullptr)) {

            }
            if (ImGui::MenuItem("Redo", nullptr)) {}
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", nullptr)) {}
            if (ImGui::MenuItem("Copy", nullptr)) {}
            if (ImGui::MenuItem("Paste", nullptr)) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    auto settings = this->config["Settings"];
    for (auto& window : this->windows) {
        window.second->_Render(settings);
    }
    this->config["Settings"] = settings;
}
