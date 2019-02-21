//
//  CustomCa.cpp
//  学习C++
//
//  Created by luqiuan on 2019/1/29.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "CustomCa.hpp"
//自定义一个Int类型 并重载运算符
class MyInt {
    
public:
    MyInt();
    MyInt(const MyInt &myint);
    ~MyInt();
    int value;
    
    //后置
    MyInt operator++(int){
        MyInt tem = *this;
        value++;
        return tem;
    }
    
    //前置
    MyInt & operator++(){
        this->value++;
        return *this;
    }
};

ostream &operator<<(ostream &cout,MyInt &myInt){
    cout<<"我是自定义整形："<<myInt.value;
    return cout;
}

MyInt::MyInt(){
    value = 0;
}

MyInt::MyInt(const MyInt &myInt){
//    cout<<"调用了拷贝构造函数"<<endl;
}

MyInt::~MyInt(){
    
}

//智能指针
class Person {
public:
    int age;
    
    Person(){age=100;}
    ~Person(){cout<<"Person的析构"<<endl;};
    
    void showAge(){cout<<"我的年龄："<<age<<endl;};
    
    //仿函数  重载()
    void operator()(string text){
        cout<<"我是一个仿函数:"<<text<<endl;
    }
};

class SmartPoint {
public:
    SmartPoint(Person *per){
        this->person = per;
    }
    ~SmartPoint(){
        cout<<"SmartPoint的析构"<<endl;
        if (this->person != NULL) {
            delete this->person;
            this->person = NULL;
        }
    }
    Person *person;
    
    //重载->运算符
    Person * operator->(){
        return this->person;
    }
    //重载*运算符
    Person& operator*(){
        return *person;
    }
};


void CustomCa(){
//    cout<<"自定义一个Int类型 并重载运算符"<<endl;
//    MyInt myint = MyInt();
//    cout<<myint<<endl;
//    myint++;
//    cout<<myint<<endl;
//    cout<<++myint<<endl;
//    cout<<myint<<endl;
    
    //new出来的对象不会自动调用析构函数
//    Person *per = new Person();
//    per->showAge();
    
    //下面采用智能指针管理
    SmartPoint smart(new Person());//开辟了栈上空间，自动释放
    smart->showAge();//重载了->运算符,这里本来有两个->->被编译器优化了
    (*smart).showAge();//重载了*运算符
//    (*smart)("哈哈");
//    Person()("哈哈");
    //1 仿函数
    Person per;
    per("dd");
    //2 仿函数
    Person()("可以这样调用");
}
