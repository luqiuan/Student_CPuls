//
//  yinyong.cpp
//  学习C++
//
//  Created by luqiuan on 2019/1/25.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "yinyong.hpp"

//交换两个值
void switchr(int &a,int &b);
void switchp(int *a,int *b);
void switchc(int a,int b);
void customcout(int a, int b);


//数组的别名
void arrtest(){
    ///////第一种
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    //引用
    int (&Arr)[10] = arr;
    for (int i  = 0; i < 10; i++) {
        cout<<Arr[i]<<"、";
    }
    cout<<endl;
    
    //第二种 使用tyedef
    typedef int(LUQIUAN)[10];
    LUQIUAN &pArr2 = arr;
    for (int i  = 0; i < 10; i++) {
        cout<<pArr2[i]<<"、";
    }
    cout<<endl;
}

int & test01(int &b){
    return b;
}

struct Person{
    int age;
};

void allocatMemory(Person **per){
    *per = (Person *)malloc(sizeof(Person));
    (*per)->age = 100;
}

void allocatMemory1(Person *& per){
    per = (Person *)malloc(sizeof(Person));
    per->age = 222;
}

void allocPerson(Person &per){
    per = *(Person *)malloc(sizeof(Person));
    per.age = 212121;
}

//两种方式初始化结构体，很明显使用引用更方便
void test02(){
    Person *per = NULL;
    allocatMemory(&per);
    cout<<per->age<<endl;
    
    Person *per1 = NULL;
    allocatMemory1(per1);
    cout<<per1->age<<endl;
    
    Person person;
    allocPerson(person);
    cout<<"hhah"<<person.age<<endl;
    
}

void yinyong(){
    test02();
    //引用的本质就是一个指针常量
    int yy = 90;
    int &YY = yy;//本质是  int * const YY = &yy;
    int a = 101,b= 202;
//    customcout(a, b);
//    switchr(a, b);
//    customcout(a, b);
//    switchp(&a, &b);
//    customcout(a, b);
//    switchc(a, b);
//    customcout(a, b);
    
    arrtest();
    
    //引用必须引用一块合法的内存空间
    //不要返回局部变量的引用，因为m局部变量在函数生命周期结束以后就会被编译器释放
    //r如果函数的返回值是引用，那么这个函数调用可以作为左值.如下
    test01(b) = 999;
    cout<<b<<endl;
}


void switchr(int &a,int &b){
    int tem = a;
    a = b;
    b = tem;
}

void switchp(int *a,int *b){
    int tem = *a;
    *a = *b;
    *b = tem;
}

void switchc(int a,int b){
    int tem = a;
    a = b;
    b = tem;
}

void customcout(int a, int b){
    cout<<"a="<<a<<" b="<<b<<endl;
}


