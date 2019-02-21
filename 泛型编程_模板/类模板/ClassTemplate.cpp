//
//  ClassTemplate.cpp
//  泛型编程_模板
//
//  Created by luqiuan on 2019/2/18.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "ClassTemplate.hpp"
#include <string>

template <class NameType, class AgeType>
//template <class NameType, class AgeType = int>//可以有默认的类型
class Person {
 
public:
    NameType name;
    AgeType age;
    
    Person(NameType nam,AgeType age){
        this->name = nam;
        this->age = age;
    }
    
    void showPerson(){
        cout<<"我叫"<<this->name<<endl;
    }
};

//-------模板类作为函数参数-------
//1、传入指定的类型
void dowork(Person<string,int> & p){
    p.showPerson();
}

//2、参数模板化
template <class T1,class T2>
void doWrok2(Person<T1,T2> & p) {
    p.showPerson();
}

//3、整体模板化
template <class T>
void doWrok3(T & p) {
    cout<<typeid(T).name()<<endl;
    p.showPerson();
}

//--------------------继承问题
//模板类的继承
template <class T>
class Base {
public:
    T prA;
    void display(){
        cout<<"我是Base类000000"<<endl;
    }
};

//继承自模板类
class SubClass1: public Base<int>
{
public:
    int AA;
    void display(){
        cout<<"我是SubClass1类000000"<<endl;
    }
};

//继承自模板类，且本身是模板类
template <class T1,class T2>
class SubClass2 :public Base<T2>{
public:
    T1 t1;
    T2 t2;
    void display();//{
//        cout<<"我是SubClass2类 "<<"T1:"<<typeid(T1).name()<<" T2:"<<typeid(T2).name()<<endl;
//    }
    
    SubClass2();
    SubClass2(T1 t1,T2 t2);//类外实现
};

//类外实现相关的函数
template <class T1,class T2>
SubClass2<T1,T2>::SubClass2(){
};

template <class T1,class T2>
SubClass2<T1,T2>::SubClass2(T1 t1,T2 t2){
    this->t2 = t2;
    this->t1 = t1;
}

template <class T1,class T2>
void SubClass2<T1,T2>::display(){
    cout<<"我是SubClass2类 "<<"T1:"<<typeid(T1).name()<<" T2:"<<typeid(T2).name()<<endl;
}

void test01(){
    Base<int> p;
    p.display();
    
    SubClass1 sub;
    sub.display();
    
    SubClass2<char,int> sub2;
    sub2.display();
    
    SubClass2<int,int> sub22(22,33);
    sub22.display();
}

void test11(){
    cout<<"类模板"<<endl;
    //类模板不支持自动类型推导 错
//    Person p("哈哈",100);
    
    //显示指定类型
//    Person<string, int> p("哈哈",100);
//    p.showPerson();
//    dowork(p);
//    doWrok2(p);
//    doWrok3(p);
    
    test01();
}
