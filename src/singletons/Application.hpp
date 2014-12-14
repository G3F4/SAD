#ifndef APPLICATION_H_DEFINED
#define APPLICATION_H_DEFINED

#include <string>
#include <iostream>
#include <map>

#include <SDL2/SDL.h>

#include "../entities/Window.hpp"


class Application
{
public:
    bool create_window(std::string ID,
            int x = 0,
            int y = 0,
            int width = 0,
            int height = 0,
            bool state = true,
            Uint32 window_flags = SDL_WINDOW_SHOWN,
            Uint32 renderer_flags = SDL_RENDERER_ACCELERATED );
    Window* get_window(std::string ID);
    std::map<std::string, Window*> get_windows(); // useful for iterating through all windows manager by application
    void hide();                            // hide all windows
    void show();                            // show all windows
    void start();                           // starts application
    void stop();                            // stops application
    void pause(Uint32 ms);                      // delay application for given amount of miliseconds
    bool is_running() { return m_running; }
    virtual ~Application();
protected:
    Application();
private:
    std::map<std::string, Window*> m_windows;
    bool m_running;
};

#endif //APPLICATION_H_DEFINED

