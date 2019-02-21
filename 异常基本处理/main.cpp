//
//  main.cpp
//  异常基本处理
//
//  Created by luqiuan on 2019/2/18.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
using namespace std;

void myFun(int a){
    throw '0';
    if (a == -1) {
        throw 1.1;
    }
}

void test(){
    try {
        myFun(-1);
    } catch (int) {
        cout<<"int类型异常"<<endl;
    }
    catch (double){
        throw;//继续向上级处理
        cout<<"double类型异常"<<endl;
    }
}

//自定义异常处理类
class MyException {
public:
    MyException(){cout<<"MyException构造函数"<<endl;}
    MyException(const MyException &e){cout<<"MyException拷贝构造函数"<<endl;}
    ~MyException(){cout<<"MyException析构函数"<<endl;}
};

int main(int argc, const char * argv[]) {
    
    exception
    
    //异常变量的声明周期：
    //如果MyException e会调用拷贝构造函数多开销一份数据
    //如果MyException *e,不new的话会提前释放u对象，new的话需要自己管理对象，在catch模块需要delete，new出来的对象
    //推荐：MyException &e 没有多余的开销，也无需自己管理
    try {
        throw MyException();
    } catch (MyException &e) {//使用引用可以减少一份空间
        cout<<"哈哈哈"<<endl;
    }
    
    
    std::cout << "Hello, World!\n";
    try {
        test();
    } catch (double) {
        cout<<"main 其他类型异常"<<endl;
    }
    catch (...){
        cout<<" main其他类型异常"<<endl;
    }
    
    
    
    //如果没有异常处理，那么成员termainate函数使程序中断。
    return 0;
}
