/* Window class header */
#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <string>

#include <SDL2/SDL.h>
#include <SDL_render.h>

#include "base/BaseObject.hpp"


class Window: public BaseObject {
public:
    Window(std::string ID = "unnamed window",               // When creating a Window instance we must provide string
            int x = 0,                                      // with ID, so Application can store it.
            int y = 0,                                      // Other parameters are not obligatory. We can create
            int width = 0,                                  // Hidden window with 0x0 dimensions in 0x0 position.
            int height = 0,                                 // It's practical solution, so we can easily create window,
            bool state = 0,                                 // and keep it hidden till all needed resources are loaded
            Uint32 window_flags = SDL_WINDOW_SHOWN,
            Uint32 renderer_flags = SDL_RENDERER_ACCELERATED);
    void set_title(std::string title);
    std::string get_title();
    SDL_Window* get_window();
    SDL_Renderer* get_renderer();
    void set_color(SDL_Color);
    SDL_Color get_color();
    void clear();
    void present();
    void minimalize();
    void maximalize();
    void hide();
    void show();
    ~Window();
protected:

private:
    SDL_Window* m_window = NULL;
    SDL_Renderer* m_renderer = NULL;
    SDL_Color m_color = {255,255,255,255};
};



#endif