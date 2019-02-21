//
//  VectorTest.cpp
//  STL
//
//  Created by luqiuan on 2019/2/19.
//  Copyright © 2019 luqiuan. All rights reserved.
//

//一个vector的实际容量一般都会大于本身已使用的空间，这是为了提交用户从存储的效率

#include "VectorTest.hpp"
#include <vector>

template <class T>
void show(T str){
    cout<<"打印："<<str<<endl;
}

//template <typename T>
void show(vector<int> v){
//    vector<T>::iterator it;// = v.begin();
    show("---------------");
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++) {
        show(*it);
    }
    show("---------------");
}

void tes1t(){
    vector<int>v;
    int arr[]  = {1,2,3,4,5,77,23};
    vector<int> v1(arr ,arr + sizeof(arr)/sizeof(arr[0]));
    vector<int> v2(v1.begin(),v1.end());
    vector<int> v3(10,100);//10个100
//    show(v3);
    if (v3.empty()) {
        show("空的");
    }else{
        show("不为空");
    }
    
    v3.resize(20);//重新设置大小
    show(v3);
    
}

//巧用swap收缩空间
void test44(){
    vector<int>v;
    for (int i = 0; i < 10000; i++) {
        v.push_back(i);
    }
    show(v.capacity());
    show(v.size());
//    巧用swap
    vector<int>(v).swap(v);//让实际容量和预分配的内存大小一致，节省资源
    //分析：vector<int>(v).swap(v):   vector<int>(v)这一段使用v来初始化一个匿名对象（x）,x的内存大小跟v的实际容量一样，之后调用swap后交换x和v的指针，这样一来就可以将预分配的n内存空间释放掉。
    show(v.capacity());
    show(v.size());
}

void test45(){
    //数据存取和操作
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    show(v.front());//第一个数
    show(v.back());//最后一个
    show(v[2]);
    
    //插入和删除
    vector<int>::iterator it = v.begin();
    v.insert(++it,2, 22);//2：表示插入几个数字，22：表示插入的值
    show(v);
    v.pop_back();
    show(v);
    v.erase(v.begin(),v.end());
    if (v.empty()) {
        show("数组全被删除了");
    }
}

void test46(){
    //逆序遍历
    vector<int> v;
    for (int i =0 ; i < 10; i++) {
        v.push_back(i+10);
    }
    
    //正序遍历
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++) {
        cout<<*it<<"-";
    }
    cout<<endl;
    
    //逆序遍历
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it ++) {
        cout<<*it<<"-";
    }
    cout<<endl;
    
    //vector的迭代器是随机访问的迭代器，支持跳跃式访问
    vector<int>::iterator it = v.begin();
    it = it + 3;//如果这种写法不报错，这个迭代器是随机访问迭代器
    show(*it);
}

void vectorTest(){
//    tes1t();
//    test44();
//    test45();
    test46();
}
