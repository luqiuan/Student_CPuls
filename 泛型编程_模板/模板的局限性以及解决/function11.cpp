//
//  function11.cpp
//  泛型编程_模板
//
//  Created by luqiuan on 2019/2/18.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "function11.hpp"
#include <string>
//36、自动类型推导。必须有参数类型才可以推导
//37、普通函数可以进行隐式类型转换，而模板函数不行（模板函数的参数必须一致）
//38、如果出现重载，优先调用普通函数（相对于模板函数）。如果想强制调用模板函数，可以使用空参数列表，myPrint<>(a,b)
//39、模板函数可以发生重载
//40、如果函数模板可以产生更好的匹配，则优先调用函数模板

class Person {
    
public:
    string name;
    int m_age;
    
    Person(string nam, int age){
        this->name = nam;
        this->m_age = age;
    }
};

template <typename T>
bool myCompare(T &a, T&b) {
    if (a == b) {
        return true;
    }
    return false;
}

//通过具体化自定义数据类型
template <>bool myCompare<Person>(Person &a,Person &b)
{
    if (a.m_age == b.m_age) {
        return true;
    }
    return false;
}

void test1(){
    int a = 9,b = 88;
    if (myCompare(a, b)) {
        cout<<"相等"<<endl;
    }else{
        cout<<"不相等"<<endl;
    }
    
    Person *pe1 = new Person("安安",90);
    Person *pe2 = new Person("稳稳",90);
    
    //比较两个自定义类型
    if (myCompare(pe1, pe2)) {
        cout<<"相等"<<endl;
    }else{
        cout<<"不相等"<<endl;
    }
}
