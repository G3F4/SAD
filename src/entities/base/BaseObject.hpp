#ifndef BASEOBJECT_H_DEFINED
#define BASEOBJECT_H_DEFINED

#include <string>

#include <SDL2/SDL.h>

#include "abstract/Object.hpp"


class BaseObject: public Object {
public:
    BaseObject() {};
    BaseObject(
            std::string ID,
            int x,
            int y,
            int width,
            int height,
            bool state);
    BaseObject(std::string ID, SDL_Point* p1, SDL_Point* p2, bool state);
    const std::string get_ID(void) { return m_ID; } // ID should be constant
    virtual int get_width(void) { return m_box.w; }
    virtual int get_height(void) { return m_box.h; }
    virtual void set_width(int width) { m_box.w = width; }
    virtual void set_height(int height) { m_box.h = height; }
    virtual SDL_Point* get_position();
    virtual void set_position(SDL_Point* p1);
    virtual void set_size(SDL_Point* p1, SDL_Point* p2);
    virtual void set_position(int x, int y);
    virtual void set_position(int x, int y, int width, int height);
    virtual int get_x_position(void) { return m_box.x; }
    virtual int get_y_position(void) { return m_box.y; }
    virtual void set_x_position(int x);
    virtual void set_y_position(int y);
    virtual bool is_active(void) { return m_state; }
    virtual void enable(void) { m_state = true; }
    virtual void disable(void) { m_state = false; }
    virtual void destroy(void);
    ~BaseObject(void) {};
protected:
    std::string m_ID;
    SDL_Rect m_box;
    bool m_state;
};

#endif /* BASEOBJECT_H_DEFINED */