#ifndef ELE_H_DEFINED
#define ELE_H_DEFINED

#include "common/Texture.hpp"
#include <string>


class ele:public Texture {
public:
    ele(std::string ID, std::string window_ID, int x, int y, int w, int h);
    void handle_events();
};


#endif