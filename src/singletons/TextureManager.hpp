
#include <map>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>

#include "../entities/common/Texture.hpp"

class TextureManager {
public:
    TextureManager();
    ~TextureManager();
    void render_window(std::string ID);
    void render_all();
    void render(std::string ID);
    Texture* get_texture(std::string ID);
    std::map<std::string, Texture*> get_textures(void) { return m_textures; }
    bool add(std::string ID, std::string file);
    bool destroy(std::string ID);
    void show(std::string ID);
    void show_all(std::string ID);
    void hide(std::string ID);
    void hide_all();
    std::string get_folder();
    void set_folder(std::string);
protected:

private:
    std::string m_folder;
    std::map<std::string, Texture*> m_textures;
};