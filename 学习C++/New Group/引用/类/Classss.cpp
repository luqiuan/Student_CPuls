//
//  Classss.cpp
//  学习C++
//
//  Created by luqiuan on 2019/1/26.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Classss.hpp"
#include <string>

class Game {
public:
    Game(){cout<<"Game构造函数"<<endl;}
    ~Game(){cout<<"Game析构函数"<<endl;}
    Game(string name):m_GameName(name){}
    string m_GameName;
};

class Phone {
public:
    Phone(){cout<<"Phone构造函数"<<endl;}
    ~Phone(){cout<<"Phone析构函数"<<endl;}
    Phone(string name):m_PhoneName(name){}
    string m_PhoneName;
    
    static void func(){
        cout<<"这是一个j静态成员函数"<<endl;
    }
};

class Person {
public:
    Person(){cout<<"Person构造函数"<<endl;}
    Person(string name,string gname, string pname):m_name(name),m_Game(gname),m_Phone(pname){}
    ~Person(){cout<<"Person析构函数"<<endl;}
    Phone m_Phone;
    Game m_Game;
    string m_name;
    void display(){
        cout<<"我叫"<<m_name<<",我的手机叫"<<m_Phone.m_PhoneName<<",我喜欢玩"<<m_Game.m_GameName<<endl;
        Phone::func();
        m_Phone.func();
    }
};

//创建一个单例类
class ChairMain {
public:
    static ChairMain *getInstance(){
        return singleMan;
    }
private:
    //默认构造函数私有化
    ChairMain(){
        cout<<"创建一个单例"<<endl;
    }
    //拷贝构造函数私有化
    ChairMain(const ChairMain &chair){
        
    }
    static ChairMain *singleMan;
};

ChairMain * ChairMain::singleMan = new ChairMain;
//
void test03(){
   ChairMain *ch = ChairMain::getInstance();
}

void test01(){
    Person p1;
    p1.display();
    Person p2("陆求安","苹果","王者荣耀");
    p2.display();
    Phone::func();
}

void start2(){
//    test01();
    test03();
}
