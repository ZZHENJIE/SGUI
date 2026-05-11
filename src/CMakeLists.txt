add_executable(${PROJECT_NAME}
# Imgui
    imgui/imgui_draw.cpp
    imgui/imgui_impl_sdlrenderer3.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_impl_sdl3.cpp
    imgui/imgui_tables.cpp
    imgui/imgui.cpp
# Core
    core/application.cpp
    core/httpclient.cpp
    core/window.cpp
# Window
    window/screener.cpp
    window/settings.cpp
    # ----
    Main.cpp
)
