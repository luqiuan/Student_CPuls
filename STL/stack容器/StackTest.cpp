//
//  StackTest.cpp
//  STL
//
//  Created by luqiuan on 2019/2/19.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "StackTest.hpp"

template <class T>
void show(T str){
    cout<<"打印："<<str<<endl;
}

//栈常用的api
void testty(){
    //构造函数
    stack<string> stac;
    stack<string> stac1(stac);//拷贝构造
    
    //赋值操作
    stack<string> stac2 = stac;
    
    //s数据存储
    stac.push("哈哈");
    stac.push("哈哈1");
    stac.push("哈哈2");
    stac.push("哈哈3");

    while (stac.size() != 0) {
        show(stac.top());
        stac.pop();
    }
    
    if (stac.empty()) {
        show("栈为空了！");
    }
}

void stackTest(){
    testty();
}
