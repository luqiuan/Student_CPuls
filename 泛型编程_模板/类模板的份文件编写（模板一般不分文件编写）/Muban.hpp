//
//  Muban.hpp
//  泛型编程_模板
//
//  Created by luqiuan on 2019/2/18.
//  Copyright © 2019 luqiuan. All rights reserved.
//


#include <iostream>
using namespace std;


#include <string>

//先让编译器看到有printLuqiuan这个函数声明，因为printLuqiuans声明本来是在Luqiuan类中，期初编译器是看不到的
template<class T1,class T2>class Luqiuan;
template<class T1,class T2>void printLuqiuan(Luqiuan<T1,T2> & lu);

template <class T1,class T2>
class Luqiuan {
    //模板类的友元函数实现类外实现（比较麻烦），printLuqiuan后面需要加<>，这是为了告诉编译器这是一个模板函数，否则编译器会把printLuqiuan当做一个普通函数处理
    friend void printLuqiuan<>(Luqiuan<T1,T2> & lu);
public:
    Luqiuan();
    void showLuqiuan();
};

void test111();
