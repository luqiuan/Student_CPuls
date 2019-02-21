//
//  main.cpp
//  STL
//
//  Created by luqiuan on 2019/2/19.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "StringTest.hpp"
#include "VectorTest.hpp"
#include "DequeTest.hpp"
#include "example.hpp"
#include "StackTest.hpp"
#include "QueueTest.hpp"
#include "ListTest.hpp"
#include "SetTest.hpp"
#include "worker.hpp"

using namespace std;

template <class T>
class Person {
public:
    Person(){}
    
    Person(T name,int age){
        this->name = name;
        this->age = age;
    }
    
    void show(){
        cout<<"我叫"<<this->name<<",我今年"<<this->age<<"岁了！"<<endl;
    }
    
private:
    T name;
    int age;
};

void test2(){
    vector<Person<string>> list;
    for (int i = 0; i < 10; i++) {
        Person<string> *per = new Person<string>("陆求安",i+11);
        list.push_back(*per);
    }
    for (vector<Person<string>>::iterator it = list.begin(); it!=list.end(); it++) {
        (*it).show();
    }
}

void test1(){
    vector<int> intArr;
    intArr.push_back(1);
    intArr.push_back(11);
    intArr.push_back(12);
    intArr.push_back(13);
    intArr.push_back(14);
    for (vector<int>::iterator it = intArr.begin(); it != intArr.end(); it++) {
        cout<<*it<<endl;
    }
}

int main(int argc, const char * argv[]) {
//    test1();
//    test2();
//    stringTest();
//    vectorTest();
//    dequeTest();
//    example();
//    stackTest();
//    queueTest();
//    listTest();
//    setTest();
    workertest();
    return 0;
}
