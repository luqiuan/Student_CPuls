//
//  Calculator.cpp
//  动态联编和静态联编
//
//  Created by luqiuan on 2019/1/30.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Calculator.hpp"

class Calculate {
public:
    virtual int getResult() = 0;//纯虚函数
    
    void setA(int A){a = A;};
    void setB(int B){b = B;};
    
    int a;
    int b;
};

//抽象类的子类必须实现父类的所有纯虚函数，不然子类依旧是抽象类，抽象类是不能实例化的
class Add : public Calculate {
public:
    virtual int getResult(){
        return a + b;
    }
};

class Sub : public Calculate {
public:
    virtual int getResult(){
        return a - b;
    }
};

void test(){
    Calculate *ca = new Add;
    ca->setA(22);
    ca->setB(11);
    cout<<ca->getResult()<<endl;
}
