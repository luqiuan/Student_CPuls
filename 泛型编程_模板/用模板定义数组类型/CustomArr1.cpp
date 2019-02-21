//
//  CustomArr.cpp
//  泛型编程_模板
//
//  Created by luqiuan on 2019/2/18.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "CustomArr1.hpp"
#include <string>

template<class T>
class CustomArr {
public:
    CustomArr(){};
    CustomArr(int cap){
        this->size = 0;
        this->cap = cap;
        this->address = new T[cap];
    }
    
    //拷贝构造
    CustomArr(const CustomArr<T> & cusArr){
        this->size = cusArr.size;
        this->cap = cusArr.cap;
        this->address = new T[cusArr.size];
        for (int i = 0; i < this->size; i++) {
            this->address[i] = cusArr.address[i];
        }
    }
    
    ~CustomArr(){
        cout<<"析构销毁！！"<<endl;
        if (this->address != NULL) {
            this->size = 0;
            this->cap = 0;
            delete [] this->address;
            this->address = NULL;
        }
    }
    
    int getSize(){
        return this->cap;
    }
    
    void push(T t1){
        this->address[this->size] = t1;
        this->size ++;
    }
    
    T & operator[](int index){
        return this->address[index];
    }
    
    
    
private:
    T *address;
    int size;
    int cap;
};

template <class T>
void display(CustomArr<T> &arr){
    for (int i = 0; i < arr.getSize(); i ++) {
        cout<<arr[i]<<endl;
    }
}

void arrtest(){
//    CustomArr<int> p(10);
//    for (int i = 0; i < 10; i++) {
//        p[i] = i+100;
//    }
//    display(p);
    
    CustomArr<string> str(10);
    str.push("luqiuan");
    str.push("chenmuzhou");
    display(str);
    
    
    CustomArr<string> *strArr = new CustomArr<string>(10);
    strArr->push("我是国人");
    display(*strArr);
    delete strArr;
    
}
