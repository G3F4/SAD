#ifndef TEXTUREMANAGERTEST_HPP
#define TEXTUREMANAGERTEST_HPP

#include "../singletons/TextureManager.hpp"


class TextureManagerTestCase {
public:
    void details (TextureManager* txs);
    void assertion_test(TextureManager* txs);
    void main_test();
};

#endif