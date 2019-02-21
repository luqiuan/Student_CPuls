//
//  Printer.cpp
//  学习C++
//
//  Created by luqiuan on 2019/1/26.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Printer.hpp"
#include <string>

class Printer {
private:
    Printer(){count = 0;}//私有化默认构造函数，防止通过默认构造函数创建其他的对象
    Printer(const Printer&p){}//私有化拷贝构造函数，防止通过拷贝构造函数拷贝出新的对象
    
    static Printer *singlePrinter;//私有化单例对象，防止外部更改
    
    int count;
    
public:
    static Printer *getInstance(){//提供外部接口获取单列
        return singlePrinter;
    }
    
    void printing(string text){
        cout<<"第"<<count++<<"次打印了："<<text<<endl;
    }
};

Printer *Printer::singlePrinter = new Printer();

void printer(){
    Printer *p = Printer::getInstance();
    p->printing("轻轻的来了");
    Printer *p1 = Printer::getInstance();
    p1->printing("轻轻的走了");
    Printer *p2 = Printer::getInstance();
    p2->printing("不带走一片云彩");
}
