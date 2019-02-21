//
//  main.cpp
//  动态联编和静态联编
//
//  Created by luqiuan on 2019/1/30.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include "Calculator.hpp"
using namespace std;

class Animal {
public:
    //虚函数 实现多态
    virtual void speak(){
        cout<<"动物在说话"<<endl;
    }
};

class Dog:public Animal {
    
public:
    void speak(){
        cout<<"小狗在说话"<<endl;
    }
};

//调用doSpeak，speak函数的地址早就绑定好了，叫静态联编，编译阶段就确定好了
//如果想让狗speak，不能提前绑定好函数的地址，所以需要在运行时q再去确定函数的地址，叫动态联编，把函数改为虚函数就可以实现
//动态联编的实现，就是将父类的方法声明为虚函数，发生了多态：父类的引用或者指针指向子类对象
void doSpeak(Animal *animal){
    animal->speak();
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    Dog dog;
//    dog.speak();
//    doSpeak(&dog);
    test();
    return 0;
}
