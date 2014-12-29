#ifndef APPLICATION_H_DEFINED
#define APPLICATION_H_DEFINED

#include <string>
#include <iostream>
#include <map>

#include <SDL2/SDL.h>

#include "../entities/Window.hpp"
#include "SingletonBase.hpp"
#include "TextureManager.hpp"
#include <memory>
#include <mutex>
#include <iostream>


class Application
{
public:
    static Application& Instance();
    bool create_window(std::string ID,
            int x = 0,
            int y = 0,
            int width = 0,
            int height = 0,
            bool state = true,
            Uint32 window_flags = SDL_WINDOW_SHOWN,
            Uint32 renderer_flags = SDL_RENDERER_ACCELERATED );
    Window* get_window(std::string ID);
    std::map<std::string, Window*> get_windows();   // useful for iterating through all windows manager by application
    void hide();                                    // hide all windows
    void show();                                    // show all windows
    void start();                                   // starts application
    void stop();                                    // stops application
    void pause(Uint32 ms);                          // delay application for given amount of miliseconds
    bool is_running() { return m_running; }
    Window* get_default_window() { return m_default_window; } // #TODO add tests for get/set default_window
    void set_default_window(std::string ID);
    virtual ~Application();
    void print_available_windows();
    Application();
    void clear();
    void present();
protected:

private:
    std::map<std::string, Window*> m_windows;
    Window* m_default_window;
    bool m_running;
    static std::unique_ptr<Application> m_instance;
    static std::once_flag m_once_flag;
};

#endif //APPLICATION_H_DEFINED

