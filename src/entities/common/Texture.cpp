#include "../../singletons/Application.hpp"
#include "Texture.hpp"


Texture::Texture(std::string ID, std::string file, int x, int y, int width, int height, std::string window_ID, double angle, SDL_RendererFlip flip, bool state):
                BaseObject(ID,x,y,width,height,state), m_file(file), m_angle(angle), m_flip(flip)
{
    m_texture = nullptr;
    m_format = nullptr;
    m_access = nullptr;
    m_window_ID = window_ID;
    m_pivot_point.x = m_box.w / 2;
    m_pivot_point.y = m_box.h / 2;
    load(); // has to be called always after initialization of ALL FIELDS!!
    if( m_texture == nullptr) {
        std::cout << "Texture not loaded." << std::endl;
    }
}

bool Texture::load() {
    m_texture = IMG_LoadTexture(Application::Instance().get_window(m_window_ID)->get_renderer(), m_file.c_str());
    if (m_texture == NULL) {
        std::cout << IMG_GetError() << std::endl;
        return false;
    } else {
        if (m_box.w == 0 || m_box.h == 0) {
            if ( SDL_QueryTexture(m_texture, m_format, m_access, &m_box.w, &m_box.h) != 0) {
                std::cout << SDL_GetError() << std::endl;
                SDL_ClearError();
            }
        } else {
            if ( SDL_QueryTexture(m_texture, m_format, m_access, NULL, NULL) != 0) {
                std::cout << SDL_GetError() << std::endl;
                SDL_ClearError();
            }
        }
        std::cout << "Texture loaded. Source:  " << m_file << \
        " | box (x, y): (" << m_box.x << ", " << m_box.y << ") | box (w,h): (" << m_box.w << ", " << m_box.h << ")" << \
        " | format: " << m_format << \
        // #TODO check why getting format doesn't work
        " | access: " << m_access << std::endl;
        // #TODO check why getting access doesn't work
        return true;
    }

}

void Texture::render() {
    SDL_RenderCopyEx(Application::Instance().get_window(m_window_ID)->get_renderer(), m_texture, NULL, &m_box, m_angle, &m_pivot_point, m_flip);
}

void Texture::flip_vertiacally() {
    if (m_flip == SDL_FLIP_NONE) {
        m_flip = SDL_FLIP_VERTICAL;
    } else if ( m_flip == SDL_FLIP_VERTICAL) {
        m_flip = SDL_FLIP_NONE;
    } else if ( m_flip == SDL_FLIP_HORIZONTAL) {
        m_flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
    }
}

void Texture::flip_horizontally() {
    if (m_flip == SDL_FLIP_NONE) {
        m_flip = SDL_FLIP_HORIZONTAL;
    } else if ( m_flip == SDL_FLIP_HORIZONTAL) {
        m_flip = SDL_FLIP_NONE;
    } else if ( m_flip == SDL_FLIP_VERTICAL) {
        m_flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
    }
}
