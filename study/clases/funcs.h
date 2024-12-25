#ifndef FUNCS_H
#define FUNCS_H

class Rectangle{
    private:
    int m_width;
    int m_height;

    public: 
    Rectangle();

    void setWidth(int width);
    void setHeight(int height);

    int getWidth();
    int getHeight();

    int area();
    int perimeter();

};


#endif
