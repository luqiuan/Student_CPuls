//
//  main.cpp
//  算法
//
//  Created by luqiuan on 2019/2/21.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


void creatV(vector<int> &v){
    for (int i = 0; i <10; i ++) {
        v.push_back(i +1);
    }
}

void printt(int val){
    cout<<val<<" ";
}

class MyPrint {
public:
    void operator()(int val){
        cout<<val<<" ";
        sumCout ++;
    }
    int sumCout;
};

//for_each 可以保存内部记录
void foreachTest(){
    vector<int> v;
    creatV(v);
    
    //使用自定义函数遍历
    cout<<"使用自定义函数 :";
    for_each(v.begin(), v.end(), printt);
    cout<<endl;
    
    //使用lambda函数遍历
    cout<<"使用lambda函数:";
    for_each(v.begin(), v.end(), [](int val){cout<<val<<" ";});
    cout<<endl;
    
    //使用仿函数遍历    for_each 可以保存内部记录
    cout<<"使用仿函数    :";
    MyPrint pr = for_each(v.begin(), v.end(), MyPrint());//会返回一个仿函数对应的类
    cout<<"   总共:"<<pr.sumCout<<endl;
    
    //for_each可以绑定参数进行输出
//    for_each(v.begin(), v.end(), <#_Function __f#>)
}


class Transform {
public:
    int operator()(int val){
        return val + 10;
    }
};

class Transform2 {
public:
    int operator()(int val,int val2){
        return val * val2;
    }
};

//transform将指定容器区间的元素搬到另一个容器，transform不会给目标t容器分配内存，所以需要我们提前分配好内存空间
//transform(1,2,3,4)
/*
 1:源容器开始迭代器
 2:源容器开始迭代器
 3:目标容器开始迭代器
 4:回调函数或者函数对象
 返回目标容器的迭代器
 */
void transformTest(){
    vector<int> v,v1;
    creatV(v);
    
    v1.resize(v.size());//提前分配好内存
    vector<int> ::iterator it = transform(v.begin(), v.end(), v1.begin(), Transform());
    for_each(v1.begin(), v1.end(), [](int val){cout<<val<<" ";});
    
    cout<<endl;
    
    //将两个容器搬运到一个目标容器
    vector<int> V1,V2,tagrtV;
    creatV(V1);
//    creatV(V2);
    for (int i = 0; i <5; i ++) {
        V2.push_back(i +1);
    }
    tagrtV.resize(v.size());//提前分配好内存
    transform(V1.begin(), V1.end(), V2.begin(), tagrtV.begin(),Transform2());
    for_each(tagrtV.begin(), tagrtV.end(), [](int val){cout<<val<<" ";});
}


//查找算法
void findTest(){
    //find算法
    vector<int> v;
    creatV(v);
    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        cout<<"找到了："<<*it<<endl;
    }
    
//    find查找自定义数据类型时，需要重载==
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    foreachTest();
//    transformTest();
    findTest();
    return 0;
}
