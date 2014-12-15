#include <iostream>

#include "BaseObject.hpp"


BaseObject::BaseObject(std::string ID, int x, int y, int width, int height, bool state):
m_ID(ID), m_state(state)
{
    m_box.x = x;
    m_box.y = y;
    m_box.w = width;
    m_box.h = height;
}

BaseObject::BaseObject(std::string ID, SDL_Point *p1, SDL_Point *p2, bool state) {
    m_ID = ID;
    BaseObject::set_size(p1, p2);
    m_state = state;
}

SDL_Point* BaseObject::get_position() {
    SDL_Point* tmp = new SDL_Point();
    tmp->x = m_box.x;
    tmp->y = m_box.y;
    return tmp;
}

void BaseObject::set_position(SDL_Point* p1) {
    if (p1->x > 0 && p1->y >0) {
        m_box.x = p1->x;
        m_box.y = p1->y;
    } else {
        std::cout << "x and y have to be positive numbers!" << std::endl;
    }
}

void BaseObject::set_position(int x, int y) {
    if (x > 0 && y >0) {
        m_box.x = x;
        m_box.y = y;
    } else {
        std::cout << "x and y have to be positive numbers!" << std::endl;
    }
}

void BaseObject::set_x_position(int x) {
    if (x >0) {
        m_box.x = x;
    } else {
        std::cout << "x have to be positive number" << std::endl;
    }

}

void BaseObject::set_y_position(int y) {
    if (y >0) {
        m_box.y = y;
    } else {
        std::cout << "y have to be positive number" << std::endl;
    }
}

void BaseObject::destroy(void) {
//    BaseObject::~BaseObject(); #TODO implement working destroy metohod
}

void BaseObject::set_size(SDL_Point *p1, SDL_Point *p2) {
    m_box.x = p1->x;
    m_box.y = p1->y;
    m_box.w = labs(p2->x - p1->x);
    m_box.h = labs(p2->y - p1->y);
}

void BaseObject::set_position(int x, int y, int width, int height) {
    if (x > 0 && y >0) {
        m_box.x = x;
        m_box.y = y;
    } else {
        std::cout << "x and y have to be positive numbers! Setting values x and y to 0." << std::endl;
        m_box.x = 0;
        m_box.y = 0;
    }
    m_box.w = width;
    m_box.h = height;
}
