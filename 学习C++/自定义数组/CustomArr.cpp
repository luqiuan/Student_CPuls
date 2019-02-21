//
//  CustomArr.cpp
//  学习C++
//
//  Created by luqiuan on 2019/1/28.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "CustomArr.hpp"


class MyArray {
    
public:
    MyArray();
    MyArray(int capacity);
    MyArray(const MyArray &arr);
    
    ~MyArray();
    
    //尾插发
    void pushBack(int value);
    int getData(int index);
    //根据所有设置值
    void setData(int value, int index);
    
    void display();
    
    int& operator[] (int index);
    
private:
    int *pAddress;
    int m_Size;
    int m_Capacity;
};

int& MyArray::operator[] (int index){
    return this->pAddress[index];
}

MyArray::MyArray(){
    this->m_Capacity = 100;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(int cap){
    this->m_Capacity = cap;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(const MyArray &arr){
    cout<<"拷贝构造函数"<<endl;
    this->pAddress = new int[arr.m_Capacity];
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    for (int i = 0; i<arr.m_Size; i++) {
        this->pAddress[i] = arr.pAddress[i];
    }
}

//MyArray::MyArray(const MyArray * &arr){
//    cout<<"拷贝构造函数"<<endl;
//    this->pAddress = new int[arr->m_Capacity];
//    this->m_Capacity = arr->m_Capacity;
//    this->m_Size = arr->m_Size;
//    for (int i = 0; i<arr->m_Size; i++) {
//        this->pAddress[i] = arr->pAddress[i];
//    }
//}

MyArray::~MyArray(){
    if (this->pAddress != NULL) {
        delete [] this->pAddress;
        this->pAddress = NULL;
        cout<<"析构了吗"<<endl;
    }
}

void MyArray::pushBack(int value){
    int size = this->m_Size;
    int cap = this->m_Capacity;
    //可以插
    if (size < cap) {
        this->pAddress[size] = value;
        this->m_Size++;
    }
    else if (size == cap){
        cout<<"满了"<<endl;
    }
}

int MyArray::getData(int index){
    if (index <= this->m_Size) {
        return this->pAddress[index];
    }
    cout<<"越界了"<<endl;
    return 0;
}

void MyArray::setData(int value, int index){
    this->pAddress[index] = value;
}

void MyArray::display(){
    for (int i = 0; i < this->m_Size; i++) {
        cout<<this->pAddress[i]<<"、";
    }
    cout<<endl;
}

ostream& operator<<(ostream &cout, MyArray &arr){
    cout<<"我是一个数组，我的第一个值="<<arr[0]<<endl;
    return cout;
}

void CustomArr(){
    MyArray *arr = new MyArray(2);
    arr->pushBack(11121);
    arr->pushBack(33);
    arr->pushBack(1);
    arr->pushBack(13);
    arr->pushBack(16);
    arr->display();
    
    MyArray *copyArr = new MyArray(*arr);//调用拷贝构造
    MyArray copyArr1 = *arr;//调用拷贝构造
    copyArr->display();
    
//    delete arr;
//    copyArr->display();
//    delete copyArr;
    
//    cout<<arr[0]<<endl;
    copyArr1[0] = 9;
    cout<<copyArr1<<endl;
}
