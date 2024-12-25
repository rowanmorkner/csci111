#include <cmath> 
#include "RightTriangle.h"

using namespace std;

void RightTriangle::setBase(unsigned base){
    m_base = base; 

}

void RightTriangle::setHeight(unsigned height){
    m_height = height;
}

unsigned RightTriangle::getHypotenuse(){
    return sqrt(pow(m_base,2) + pow(m_height,2));
} 

unsigned RightTriangle::getArea(){
    return (m_base*m_height)/2;
} 

unsigned RightTriangle::getPerimeter(){
    return m_base + m_height + getHypotenuse();
}