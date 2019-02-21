//
//  Muban.cpp
//  泛型编程_模板
//
//  Created by luqiuan on 2019/2/18.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Muban.hpp"
//建议：模板类不要份文件编写，写到一个文件中即可，类内进行声明和实现，最后把文件后缀改成hpp(这是约定俗成的写法)
template<class T1, class T2>
Luqiuan < T1, T2>::Luqiuan(){
    cout<<"我是LUqiuan的构造函数"<<endl;
}

template<class T1, class T2>
void Luqiuan< T1,  T2>::showLuqiuan(){
    cout<<"我是LUqiuan的showLuqiuan"<<endl;
}

void test111(){
    Luqiuan<int, int> lu;
    lu.showLuqiuan();
}
