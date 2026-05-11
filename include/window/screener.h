#pragma once

#include "core/window.h"

class Screener : public Window{
public:
    Screener();
    ~Screener();
public:
    const char * WindowLabel() override;
    void LoadConfig(nlohmann::json & json) override;
    void SaveConfig(nlohmann::json & json) override;
    void Render(nlohmann::json &settings) override;
};
