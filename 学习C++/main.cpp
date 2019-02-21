//
//  main.cpp
//  学习C++
//
//  Created by luqiuan on 2018/9/16.
//  Copyright © 2018年 luqiuan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "game2.hpp"
#include "game1.hpp"
#include "yinyong.hpp"
#include "Circle.hpp"
#include "Cube.hpp"
#include "Classss.hpp"
#include "Printer.hpp"
#include "FriendTest.hpp"
#include "CustomArr.hpp"
#include "CustomCa.hpp"

using namespace std;

struct Person {
    string name;
    string addr;
};

void initVector(int size,vector<Person> &vec){
    
    for (int i = 0; i<size; i++) {
        struct Person per;
        string str = "陆求安-";
        per.name = str + to_string(i+1);
        string adr = "长沙-";
        per.addr  = adr + to_string(i+1);
        vec.push_back(per);
    }
}

void traverseVec(vector<Person> &vec){
    struct Person per;
    while (!vec.empty()) {
        per = vec.back();
        vec.pop_back();
        cout<<"name:"<<per.name<<"  addr:"<<per.addr<<endl;
    }
}

//使用迭代器
void inter_for(vector<Person> &vt){
    Person per;
    vector<Person>::iterator iter;
    for (iter = vt.begin(); iter != vt.end(); iter++) {
        per = *iter;
        cout<<"name:"<<per.name<<"  addr:"<<per.addr<<endl ;
    }
}


int main(int argc, const char * argv[]) {
    
    
//    vector<Person> perVec;
//    initVector(10, perVec);
//    inter_for(perVec);
//
//    LOL::LOLL::test();
//    King::test();
    
    int aa = 12;
    int *pt = &aa;
    int & aaa = *pt;
    int bb = 121;
    pt = &bb;
//    cout << aaa<<endl;
    
//    yinyong();
//    start2();
    
//    printer();//打印机单例
//    friendTest();
//    CustomArr();
    CustomCa();//运算符重载

    return 0;
}
