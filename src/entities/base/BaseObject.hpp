#ifndef BASEOBJECT_H_DEFINED
#define BASEOBJECT_H_DEFINED

#include <string>
//#include <map>

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
//    BaseObject(std::string ID, SDL_Point* p1, SDL_Point* p2, bool state);
    std::string get_ID(void) { return m_ID; }
    void set_ID(std::string ID) { m_ID = ID; }
    virtual int get_width(void) { return m_box.w; }
    virtual int get_height(void) { return m_box.h; }
    virtual void set_width(int width) { m_box.w = width; }
    virtual void set_height(int height) { m_box.h = height; }
    virtual SDL_Point* get_positon(void);
    virtual void set_position(SDL_Point* point);
    virtual void set_position(int x, int y);
    virtual int get_x_position(void) { return m_box.x; }
    virtual int get_y_position(void) { return m_box.y; }
    virtual void set_x_position(int x) { m_box.x = x; }
    virtual void set_y_position(int y) { m_box.y = y; }
//    virtual void move(SDL_Point* p1, SDL_Point* p2); // #TODO check if it's needed
//    virtual void move(int x1, int y1, int x2, int y2); // #TODO check if it's needed
    virtual bool is_active(void) { return m_state; }
    virtual void enable(void) { m_state = true; }
    virtual void disable(void) { m_state = false; }
    virtual void destroy(void);
//    virtual void handle_events(void);

    ~BaseObject(void) {};
protected:
    std::string m_ID;
    SDL_Rect m_box;
    bool m_state;
//    map<std::string, std::function()*> m_events; #TODO implement Backbone.js events system
};

#endif /* BASEOBJECT_H_DEFINED */