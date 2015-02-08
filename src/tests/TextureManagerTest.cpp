/* Texture Manager Test definitions */
#include <SDL2/SDL_image.h>

#include "TextureManagerTest.hpp"
#include "../utils/test-tools.hpp"
#include "../singletons/Application.hpp"
#include "../singletons/Events.hpp"

#include "../entities/elephant.h"

void TextureManagerTestCase::details(TextureManager *txs) {

}

void TextureManagerTestCase::assertion_test(TextureManager *txs) {
    TextureManager& GFX = TextureManager::Instance();
    std::cout << std::endl;
}

void TextureManagerTestCase::main_test() {
    Application& APP = Application::Instance();
    TextureManager& GFX = TextureManager::Instance();
    Events& EVENTS = Events::Instance();
    APP.start();
    APP.create_window("Okno testowe", 200, 200, 640, 480);
    GFX.load("test", "ele.png", 200, 200, 200, 200, "Okno testowe");

    while(APP.is_running()) {
        APP.clear();
        GFX.render_all();
        EVENTS.handle();
        if (EVENTS.mouse_clicked("left")) {
            GFX.get_texture("test")->set_x_position(GFX.get_texture("test")->get_x_position()+100);
        }
        APP.present();
    }



































//    TextureManager& GFX2 = TextureManager::Instance();
//    assertion_test(&GFX);
//    APP.create_window("default", 200, 200, 200, 200, true, SDL_WINDOW_SHOWN, SDL_RENDERER_ACCELERATED);
//    GFX.load("test", "clare.jpg", 0, 0);
//    GFX2.load("test2", "ele.png", 100, 100, 100, 100);
//    int i = 0;
//    APP.start();
//    while (APP.is_running()) {
//        APP.clear();
//        Events::Instance().handle();
//        if (i == 30) {
//            GFX.get_texture("test")->flip_vertiacally();
//        }
//        if (i == 60) {
//            GFX.get_texture("test")->flip_vertiacally();
//        }
//        if (i == 95) {
//            GFX.get_texture("test")->flip_horizontally();
//        }
//        if (i == 130) {
//            GFX.get_texture("test")->flip_horizontally();
//        }
//        if ( i < 45) {
//            APP.get_window("default")->set_x_position(APP.get_window("default")->get_x_position()+1);
//        }
//        if ( i > 45 && i < 90 ) {
//            APP.get_window("default")->set_y_position(APP.get_window("default")->get_y_position()+1);
//        }
//        if ( i > 90 && i < 135) {
//            APP.get_window("default")->set_x_position(APP.get_window("default")->get_x_position()-1);
//        }
//        if ( i > 135 ) {
//            APP.get_window("default")->set_y_position(APP.get_window("default")->get_y_position()-1);
//        }
//        TextureManager::Instance().get_texture("test")->render();
//        GFX.get_texture("test2")->set_x_position(i);
//        GFX.get_texture("test2")->set_width(50+i);
//        GFX.get_texture("test2")->set_height(50+i);
//        GFX.get_texture("test2")->set_angle(i*2);
//        GFX.get_texture("test2")->render();
//        APP.get_window("default")->set_width(200+i);
//        APP.get_window("default")->set_height(200+i);
//        APP.present();
//        SDL_Delay(10);
//        i++;
//    }
//
//    SDL_Delay(1000);
}
