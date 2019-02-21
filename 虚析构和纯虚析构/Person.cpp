//
//  Person.cpp
//  虚析构和纯虚析构
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Person.hpp"
#include <string>

class Person {
public:
    virtual void myName(){
        cout<<"我是一个人"<<endl;
    }
    
    //虚析构函数
//    父类的虚析构函数,当父类对象指向子类对象时，如果不把父类的析构定义为虚析构，delete会导致子类的析构无法调用，所以需要用virtual修饰
//    virtual ~Person(){
//        cout<<"我是Person析构函数"<<endl;
//    }
    
    
    //纯虚析构函数，不仅需要声明，还要实现，类内声明，类外实现
    //如果类中存在纯虚析构函数，那这个类也是一个抽象类，不能实例化
    virtual ~Person() = 0;
};

//类外实现纯虚析构函数
Person::~Person(){cout<<"我是Person的纯虚析构函数"<<endl;}

class Student : public Person {
public:
    Student(char *na){
        this->name = new char[strlen(na) + 1];
        strcpy(this->name, na);
    }
    
    virtual void myName(){
        cout<<"我是一学生:"<<this->name<<endl;
    }
    
    char *name;
    
    //父类的虚构函数Student
    ~Student(){
        cout<<"我是Student析构函数"<<endl;
        if (this->name != NULL) {
            delete [] this->name;
            this->name = NULL;
        }
    }
};

void test(){
    cout<<"哈哈哈"<<endl;
    Person *per = new Student("陆求安");
    per->myName();
    delete per;
}
