//
//  SetTest.cpp
//  STL
//
//  Created by luqiuan on 2019/2/20.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "SetTest.hpp"
#include <set>

void show(set<int> & se){
    cout<<"输出:";
    for (set<int>::iterator it = se.begin(); it != se.end(); it++) {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}

void te(){
    set<int> se;//关联式容器 会自动排好序
    
    //一种方式插入
    se.insert(290);
    se.insert(22);
    se.insert(23);
    se.insert(244);
    se.insert(21);
    show(se);
    
    if(!se.empty()){
        cout<<"不为空"<<endl;
    }
    
    se.erase(21);//直接删除对应的值
    show(se);
    se.erase(--se.end());//删除迭代器指向的值,为什么删除endH会报错。end必须先自减才会指向最后一个元素
    show(se);
    
    
    
    se.insert(2424);
    se.insert(2144);
    se.insert(2144);
    pair<set<int>::iterator, bool> p = se.insert(2144);
    if (p.second) {
        cout<<"插入"<<*(p.first)<<"成功"<<endl;
    }else{
        cout<<"插入"<<*(p.first)<<"失败"<<endl;
    }
    //查找操作 set没有value  key就是value
    set<int>::iterator it = se.find(2424);//查找键值key是否存在，存在的话返回该元素的迭代器，若不存在返回set.end()
    //判断是否找到
    if (it != se.end()) {
        cout<<"找到了:"<<*it<<endl;
    }else{
        cout<<"没找到"<<endl;
    }
    
    //count(key) 查找键key的元素个数  set中不会存在重复的元素 multiset中的元素可以重复
    cout<<"个数："<<se.count(2144)<<endl;
    
    show(se);
    //lower_bound(keyElem)  返回第一个key>=keyElem元素的迭代器
    it = se.lower_bound(23);
    if (it != se.end()) {
        cout<<"找到了:"<<*it<<endl;
    }else{
        cout<<"没找到"<<endl;
    }
    
    //upper_bound(keyElem)  返回第一个key>keyElem元素的迭代器
    it = se.upper_bound(23);
    if (it != se.end()) {
        cout<<"找到了:"<<*it<<endl;
    }else{
        cout<<"没找到"<<endl;
    }
    
    //equal_range(keyElem)  返回容器中key和keyElem相等的上下限的两个迭代器
    pair<set<int>::iterator, set<int>::iterator> pa = se.equal_range(24);
    it = pa.first;
    if (it != se.end()) {
        cout<<"找到了:"<<*it<<endl;
    }else{
        cout<<"没找到"<<endl;
    }
    it = pa.second;
    if (it != se.end()) {
        cout<<"找到了:"<<*it<<endl;
    }else{
        cout<<"没找到"<<endl;
    }
    
    
    
}

//利用仿函数
class compare {
public:
    bool operator()(int v1,int v2){
        return v1 > v2;
    }
};


class Student {
    
public:
    string name;
    int age;
    
    Student(string name,int age){
        this->name = name;
        this->age = age;
    }
    
    //为什么重载不行
//    bool operator < (const Student &stu){
//        return stu.age > this->age;
//    }
};

class StudentCompare {
public:
    bool operator()(Student s1,Student s2){
        return s1.age > s2.age;
    }
};

void teee(){
    //set容器排序 默认排序从小到大
    //从大到小  插入之前指定,使用仿函数实现
    set<int,compare> se;
    se.insert(22);
    se.insert(23);
    se.insert(26);
    se.insert(222);
    se.insert(2221);
    for (set<int,compare>::iterator it = se.begin(); it != se.end(); it++) {
        cout<<*it<<endl;
    }
    
    
    //存储自定义类型
    set<Student,StudentCompare> sList; //在set中插入自定义类型，因为会对自定义类型排序，所以必须提前指定一个排序规则，可以借助仿函数
    Student st1("我是",22);
    Student st2("我是1",221);
    Student st3("我是2",222);
    Student st4("我是3",223);
    sList.insert(st1);
    sList.insert(st2);
    sList.insert(st4);
    sList.insert(st3);
    for (set<Student,StudentCompare>::iterator it = sList.begin(); it != sList.end(); it++) {
        cout<<(*it).name <<endl;
    }
}



void setTest(){
//    te();
    teee();
}
