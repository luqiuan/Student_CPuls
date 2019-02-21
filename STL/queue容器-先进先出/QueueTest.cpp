//
//  QueueTest.cpp
//  STL
//
//  Created by luqiuan on 2019/2/19.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "QueueTest.hpp"
#include <queue>
template <class T>
void show(T str){
    cout<<"打印："<<str<<endl;
}

void queueTest(){
    queue<int> que;
    queue<int> que1(que);//拷贝构造
    queue<int> que2 = que;//赋值操作
    
    //存取、插入和删除
    que.push(100);//往对位插入一个
    que.push(200);//往对位插入一个
    que.push(300);//往对位插入一个
    que.pop();//从对头移除一个元素
    que.back();//返回最后一个元素
    que.front();//返回第一个元素
    show(que.back());
    show(que.front());
    
    que.empty();//是否为空
    que.size();//大小
}
