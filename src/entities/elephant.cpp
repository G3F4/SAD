#include "elephant.h"
#include "../singletons/Events.hpp"

elephant::elephant(std::string ID, std::string window_ID, int x, int y, int w, int h){
        TextureManager::Instance().load(ID, "ele.png", x, y, w, h, window_ID, true);
}

void elephant::handle_events() {
        if (Events::Instance().key_pressed("left")) {

        }

}
