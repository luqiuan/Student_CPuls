//
//  main.cpp
//  泛型编程_模板
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include "sort.hpp"
#include "function11.hpp"
#include "ClassTemplate.hpp"
#include "Muban.hpp"
#include "CustomArr1.hpp"
using namespace std;
//类型参数化  泛型编程--模板技术
template <class T> //告诉编译器下面如果出现了T不要报错，T是一个通用的类型
void mySwap(T &a, T &b){
    T tmp = b;
    b = a;
    a = tmp;
}

template <typename T>
void mySwap1(T &a, T &b){
    T tmp = b;
    b = a;
    a = tmp;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a = 10,b = 20;
//    mySwap(a, b);//s自动推导类型
//    mySwap<int>(a, b);//显示指定类型
//    mySwap1<int>(a, b);
    //模板必须要指定T才可以使用
    
//    cout<<"a="<<a<<" b="<<b<<endl;
    
//    test();
//    test1();
    test11();
    arrtest();
    return 0;
}
