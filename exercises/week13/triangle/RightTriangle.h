#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

class RightTriangle{

    private: 
    unsigned m_base = 3;
    unsigned m_height = 4;
    unsigned m_hypo = 5;

    public: 
    void setBase(unsigned base);
    void setHeight(unsigned height);

    unsigned getHypotenuse(); 
    unsigned getArea(); 
    unsigned getPerimeter();

};

#endif