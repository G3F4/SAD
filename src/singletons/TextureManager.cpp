/* TextureManager definitions */
#include "TextureManager.hpp"

TextureManager::TextureManager() {
    m_folder = "/assets/images/";
	std::cout << "TextureStash singleton instantiated." << std::endl;
}

TextureManager::~TextureManager() {
    std::cout << "TextureStash singleton destroyed." << std::endl;
}

void TextureManager::render(std::string ID) {
//    SDL_RenderCopyEx(
//            app.get_window(ID)->get_renderer(),
//            m_textures[ID]->get_texture(),
//            NULL, m_textures[ID]->get_box(),
//            m_textures[ID]->get_angle(),
//            m_textures[ID]->get_pivot_point(),
//            m_textures[ID]->get_flip());
}

void TextureManager::render_all() {
    for ( auto tex: m_textures) {
        render(tex.first);
    }
}

Texture *TextureManager::get_texture(std::string ID) {
    return m_textures[ID];
}
