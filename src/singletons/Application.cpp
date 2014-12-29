#include "Application.hpp"


std::unique_ptr<Application> Application::m_instance;
std::once_flag Application::m_once_flag;

Application& Application::Instance() {
    std::call_once(m_once_flag, [] {
        m_instance.reset(new Application);
    });
    return *m_instance.get();
}

Application::Application() {
    m_running = false;
    std::cout << "Application Manager created!" << std::endl;
}

Application::~Application() {
    std::cout << "Application Manager destroyed!" << std::endl;
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
        if (m_windows.size() == 1) {
            m_default_window = m_windows[ID];
        }
    }
    return false;
}

Window *Application::get_window(std::string ID) {
    if (m_windows[ID] == nullptr) {
        std::cout << "There is no Window with ID: " << ID << std::endl \
                    << "Specify corrent ID to get Window; " << std::endl;
        std::string new_ID = "";
        std::cin >> new_ID;
        if (new_ID == "print_windows") {
            print_available_windows();
        }
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

void Application::set_default_window(std::string ID) {
    if (m_windows.count(ID) == 0) {
        std::cout << "Window with ID: " << ID << " doesn't exits!" << std::endl \
                    << "Please select other ID: ";
        std::string new_ID = "";
        std::cin >> new_ID;
        set_default_window(new_ID);
    } else {
        m_default_window = m_windows[ID];
    }

}

void Application::print_available_windows() {
    for (auto win: m_windows) {
        std::cout << win.first << std::endl;
    }
}

void Application::clear() {
    for (auto win: m_windows) {
        win.second->clear();
    }
}

void Application::present() {
    for (auto win: m_windows) {
        win.second->present();
    }
}
