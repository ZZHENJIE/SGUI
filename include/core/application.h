#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include "core/window.h"

class Application {
private:
    std::unordered_map<std::string, std::unique_ptr<Window>> windows;
    nlohmann::json config;

    void initWindows();
public:
    template<typename T>
    void addWindow(std::string name, std::unique_ptr<T> window){
        windows[name] = std::move(window);
    }
public:
    Application();
    ~Application();
    void render();
};
