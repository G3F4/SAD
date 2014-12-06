#include "BaseObject.hpp"

BaseObject::BaseObject(std::string ID, int x, int y, int width, int height, bool state):
m_ID(ID), m_state(state)
{
    m_box.x = x;
    m_box.y = y;
    m_box.w = width;
    m_box.h = height;
}

//BaseObject::BaseObject(std::string ID, SDL_Point *p1, SDL_Point *p2, bool state) {
//    m_ID = ID;
//    m_box.x = p1->x;
//    m_box.y = p1->y;
//    m_box.w = labs(p2->x - p1->x);
//    m_box.h = labs(p2->y - p1->y);
//    m_state = state;
//}

SDL_Point* BaseObject::get_positon() {
    SDL_Point* tmp = new SDL_Point();
    tmp->x = m_box.x;
    tmp->y = m_box.y;
    return tmp;
}

void BaseObject::set_position(SDL_Point* point) {
    m_box.x = point->x;
    m_box.y = point->y;
}

void BaseObject::set_position(int x, int y) {
    m_box.x = x;
    m_box.y = y;
}

void BaseObject::destroy() {
    this->~BaseObject();
}