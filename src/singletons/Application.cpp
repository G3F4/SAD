#include "Application.hpp"

Application::Application() {
    m_running = false;
}

Application::~Application() {

}

bool Application::create_window(std::string ID, int x, int y, int width, int height, bool state, Uint32 window_flags, Uint32 renderer_flags) {
    if (m_windows.count(ID) > 0) {
        std::cout << "Window with ID: " << ID << " already exits!" << std::endl \
                    << "Please select other ID: ";
        std::string new_ID = "";
        std::cin >> new_ID;
        create_window(new_ID, x, y, width, height, state, window_flags, renderer_flags);
    } else {
        m_windows[ID] = new Window(ID, x, y, width, height, state, window_flags, renderer_flags);
    }
    return false;
}

Window *Application::get_window(std::string ID) {
    if (m_windows[ID] == nullptr) {
        std::cout << "There is no Window with ID: " << ID << std::endl \
                    << "Specify corrent ID to get Window; " << std::endl;
        std::string new_ID = "";
        std::cin >> new_ID;
        get_window(new_ID);
    } else {
        return m_windows[ID];
    }
}

void Application::hide() {
    for (auto win: m_windows) { // c++11 iterating style
        win.second->hide();
    }
}

void Application::show() {
    for (auto win: m_windows) {
        win.second->show();
    }
}

void Application::start() {
    m_running = true;
}

void Application::stop() {
    m_running = false;
}

void Application::pause(Uint32 ms) {
    SDL_Delay(ms);
}

std::map<std::string, Window *> Application::get_windows() {
    return m_windows;
}
