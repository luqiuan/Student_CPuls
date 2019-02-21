//
//  DequeTest.cpp
//  STL
//
//  Created by luqiuan on 2019/2/19.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "DequeTest.hpp"
#include <vector>
#include <deque>
//相对于vector是单向连续存储列表，deque是一种双向连续的存储容器
//deque和vector的最大差异，一：在于dequey允许使用常数项时间对头端进行元素的插入和删除操作；二：在于deque没有容量的概念，因为他是动态的以分段连续空间组合而成，随时可以增加一段新的空间并连接起来。换句话说像vector那样当旧空间不足而重新分配一块更大的空间，然后复制元素，再释放旧空间的操作，不会发生在deque身上，也因此deque没有必要提供所谓的空间保留(reserve)功能。

template <class T>
void show(T str){
    cout<<"打印："<<str<<endl;
}

//template <typename T>
void show(deque<int> v){
    show("---------------");
    for (deque<int>::iterator it = v.begin(); it != v.end(); it ++) {
        show(*it);
    }
    show("---------------");
}

void testt(){
    deque<int>d;
    d.push_back(12);
    d.push_front(13);
    show(d);
    
    deque<int> d1(d.begin(),d.end());
    d1.push_front(1000);
    show(d1);
}


void dequeTest(){
    testt();
}
