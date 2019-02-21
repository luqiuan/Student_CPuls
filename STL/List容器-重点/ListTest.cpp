//
//  ListTest.cpp
//  STL
//
//  Created by luqiuan on 2019/2/19.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "ListTest.hpp"
using namespace std;
bool compare(int a, int b){
    return a > b;
}
//list不仅是一个双向链表，而且是一个双向循环列表
void teest(){
    list<int> myList;
    for (int i = 0;i < 10; i++) {
        myList.push_back(i + 10);
    }
    
//    list<int>::_Nodeptr it = myList._Myhead->_Next;
}


template <class T>
void show(T str){
    cout<<"打印："<<str<<endl;
}

void printt(list<int> lis){
    cout<<"打印：";
    for (list<int>:: reverse_iterator it = lis.rbegin(); it != lis.rend(); it ++) {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}

void APItest(){
    list<int> list1;
    list<int> list2(list1.begin(),list1.end());//构造函数
    list1 = list<int>(10,99);//拷贝10个99
    list2 = list<int>(list1);//拷贝构造函数
    
    //插入和删除
    list1.push_back(12);//在容器尾部加入一个元素
    list1.pop_back();//删除容器最后一个元素
    list1.push_front(13);//在容器开头插入一个元素
    list1.pop_front();//在容器开头移除一个元素
    printt(list1);
    
//    list1.insert(list1.begin(), 14);//在begin位置插入14，并返回新数据的位置
    list1.insert(++list1.begin(), 2, 15);//在begin++ 连续插入2个15
    printt(list1);
    
    //清空
    printt(list2);
    list2.clear();
    printt(list2);
    
    //擦除
    list2.erase(list2.begin(),list2.end());//返回下一个元素的位置
//    list2.erase(list2.begin());
    
    //移除
    list1.remove(99);//移除链表中所有的99
    printt(list1);
    
    list2.front();
    list2.back();
    show(list2.back());
    
    //翻转
    list2.reverse();
    
    //排序
//    sort(list2.begin(),list2.end());//失败：所有不支持随机访问迭代器的容器，不可以用系统提供的算法
    //list类内部会提供sort函数
    list2.sort();//从小到大
    list2.sort(compare);
}


//自定义数据类型
class Person {
    
public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
    
    //重载==
    bool operator== (const Person &per){//必须要加const,否则会报错
        if(per.name == this->name && per.age == this->age){
            return true;
        }
        return false;
    }
};

void printP(list<Person> lis){
    cout<<"打印："<<endl;
    for (list<Person>:: reverse_iterator it = lis.rbegin(); it != lis.rend(); it ++) {
        cout<<(*it).name<<"，年龄："<<(*it).age<<endl;
    }
}

bool com(Person p1,Person p2){
    return p1.age < p2.age;
}

void testttt(){
    list<Person> L;
    Person per1("到大",120);
    Person per2("到大1",1201);
    Person per3("到大2",12);
    Person per4("到大3",13);
    Person per5("到大4",124);
    L.push_back(per1);
    L.push_back(per2);
    L.push_back(per3);
    L.push_back(per4);
    L.push_back(per5);
    printP(L);
    cout<<"排序："<<endl;
    L.sort(com);//按年龄大小排序
    printP(L);
    
    //在list中删除自定义数据类型，需要在自定义类中重载==操作符，因为remove函数内部使用了==来查找
//    L.remove(per5);
    if (per2 == per1) {
        
    }
}


void tes(){
    //翻转排序
    list<int> ll;
    ll.push_back(12);
    ll.push_back(13);
    ll.push_back(14);
    ll.push_back(15);
    ll.push_back(16);
    printt(ll);
    cout<<"翻转："<<endl;
    ll.reverse();
    printt(ll);
    cout<<"排序："<<endl;
//    ll.sort();
    ll.sort(compare);
    printt(ll);
}

void listTest(){
//    APItest();
    testttt();
//    tes();
}
