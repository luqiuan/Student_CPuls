//
//  Circle.hpp
//  学习C++
//
//  Created by luqiuan on 2019/1/25.
//  Copyright © 2019 luqiuan. All rights reserved.
//
#include <iostream>
#include "cccc.h"
using namespace std;
class Circle {
    
private:
    int m_R;
    
public:
    void setM_R(int r);
    double calculateZC();
    void display();
};
void start();
