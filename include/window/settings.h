#pragma once

#include "core/window.h"

class Settings : public Window{
public:
    Settings();
    ~Settings();
public:
    const char * WindowLabel() override;
    void LoadConfig(nlohmann::json & json) override;
    void SaveConfig(nlohmann::json & json) override;
    void Render(nlohmann::json &settings) override;
};
