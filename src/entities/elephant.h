#ifndef ELE_H_DEFINED
#define ELE_H_DEFINED

#include <string>
#include "../singletons/TextureManager.hpp"


class elephant{
public:
    elephant(std::string ID, std::string window_ID, int x, int y, int w, int h);
    void handle_events();
};


#endif