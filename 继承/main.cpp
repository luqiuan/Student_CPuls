//
//  main.cpp
//  继承
//
//  Created by luqiuan on 2019/1/29.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Base {
    
public:
    Base(){
        this->a = 11;this->b=22;
        this->ch = new char [5];
        strcpy(this->ch, "awqwqwqwqw");
        cout<<ch<<endl;
    };
    Base(const Base *base){this->a = base->a;this->b = base->b;cout<<"指针型拷贝构造函数"<<endl;this->ch = "12344";}
    Base(const Base &base){this->a = base.a;this->b = base.b;cout<<"引用型拷贝构造函数"<<endl;this->ch = "12344";}
    ~Base(){
        if (this->ch != NULL) {
            delete [] this->ch;
        }
        cout<<"析构函数"<<endl;
        
    }
    int a;
    int b;
    char *ch;
    
    bool operator==(const Base &ba){
        cout<<"c==运算符"<<endl;
        return ba.a == a && ba.b == b;
    }
    
    bool operator==(const Base *ba){
        cout<<"c==运算符-指针"<<endl;
        return ba->a == a && ba->b == b;
    }
};

class Son :public Base{
    
public:
    Son();
    int c;
};

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    
//    Base ba = Base();
//    ba.a = 100;
//    ba.b = 200;
//
//    Base bb(&ba);
//
//    if(ba == bb){
//        cout<<"相等了"<<endl;
//    }
    
    Base *b = new Base();
    Base *a = new Base(*b);
//
//    if(*b==a){
//        cout<<"相等了"<<endl;
//    }
    
    delete b;
    delete a;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    

    return 0;
}

