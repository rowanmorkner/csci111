
#include "funcs.h"

//constructor
Rectangle::Rectangle(){
    m_width = 0;
    m_height = 0;
}

//setters 
void Rectangle::setHeight(int height){
    m_height = height;
}
void Rectangle::setWidth(int width){
    m_width = width;
}

// getters
int Rectangle::getHeight(){
    return m_height;
}

int Rectangle::getWidth(){
    return m_width;
}

// member functions     
int Rectangle::area(){
    return m_height *m_width;
}

int Rectangle::perimeter(){
    return (2*(m_height+m_width));
}


