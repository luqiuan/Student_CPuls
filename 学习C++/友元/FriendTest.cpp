
//
//  FriendTest.cpp
//  学习C++
//
//  Created by luqiuan on 2019/1/26.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "FriendTest.hpp"
#include <string>
//友元函数
class MySelf {
    friend void visit (const MySelf *self);//友元函数
    friend class Custom;//友元类
public:
    MySelf():my_room("客厅"),mybedroom("卧室"){};
    string my_room;
private:
    string mybedroom;
};

void visit(const MySelf *self){
    cout<<"友元函数我到了:"<<self->my_room<<endl;
    cout<<"友元函数我到了:"<<self->mybedroom<<endl;
}

class Custom {
public:
    void visit1();
    MySelf *self;
    Custom(){
        self = new MySelf();
    }
};

void Custom::visit1(){
    cout<<"友元类我到了:"<<self->my_room<<endl;
    cout<<"友元类我到了:"<<self->mybedroom<<endl;
}


void friendTest(){
    MySelf my;
    visit(&my);
    
    Custom cus;
    cus.visit1();
}
