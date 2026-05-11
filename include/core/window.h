#pragma once

#include "nlohmann/json.hpp"

class Window{
    friend class Application;
private:
    bool open;
    void _Render(nlohmann::json &settings);
public:
    Window();
    virtual ~Window();
    void Open();
    void Close();
    bool IsOpen();
public:
    virtual const char * WindowLabel() = 0;
    virtual void OpenInit();
    virtual void CloseRelease();
    virtual void LoadConfig(nlohmann::json & json) = 0;
    virtual void SaveConfig(nlohmann::json & json) = 0;
    virtual void Render(nlohmann::json &settings) = 0;
};
