#ifndef TEXTURE_H_DEFINED
#define TEXTURE_H_DEFINED

#include <SDL2/SDL.h>            // SDL2
#include <SDL2/SDL_video.h>      // SDL2
#include <SDL2/SDL_image.h>      // SDL2_Image

#include <iostream>
#include <string>

#include "../base/BaseObject.hpp"


class Texture: public BaseObject {
public:
	Texture(std::string ID,
            std::string file = "",
            int x = 0,
            int y = 0,
            int width = 0,
            int height = 0,
            double angle = 0,
            SDL_Point* pivot_point = nullptr,
            SDL_RendererFlip flip = SDL_FLIP_NONE,
            bool state = true);
    SDL_Texture* get_texture(void) { return this->m_texture; }
    void set_texture(SDL_Texture* texture) { this->m_texture = texture; }
    std::string get_file() { return m_file; }
    void set_file(std::string file) { m_file = file; }
    std::string get_window_ID() { return m_window_ID; }
    void set_window_ID(std::string ID) { m_window_ID = ID; }
    double get_angle() { return m_angle; }
    void set_angle(double angle) { m_angle = angle; }
    SDL_Point* get_pivot_point() { return m_pivot_point; }
    void set_pivot_point(SDL_Point* pivot_point) { m_pivot_point = pivot_point; }
    SDL_RendererFlip get_flip() { return m_flip; }
    void set_flip(SDL_RendererFlip flip) { m_flip = flip; }
private:
	std::string m_file;
    SDL_Texture* m_texture;
    std::string m_window_ID; // ID of window to render
    double m_angle = 0;
    SDL_Point* m_pivot_point ;
    SDL_RendererFlip m_flip;
};

#endif /* TEXTURE_H_DEFINED */
