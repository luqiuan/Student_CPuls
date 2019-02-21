//
//  Circle.cpp
//  学习C++
//
//  Created by luqiuan on 2019/1/25.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Circle.hpp"
const double pi = 3.14;

double Circle::calculateZC(){
    return 2 * m_R * pi;
}

void Circle::display(){
    cout<<"圆的半径是："<<m_R<<",圆的周长是："<<calculateZC()<<endl;
}

void Circle::setM_R(int r){
    m_R = r;
}

void start(){
    Circle circle;
    circle.setM_R(10);
    circle.display();
    circle.setM_R(20);
    circle.display();
    show();
}
