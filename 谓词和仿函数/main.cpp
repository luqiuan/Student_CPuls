//
//  main.cpp
//  谓词和仿函数
//
//  Created by luqiuan on 2019/2/21.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//仿函数
class CreateThen20 {
    
public:
    bool operator()(int val){//返回值为bool的仿函数 叫谓词
        return val>20;
    }
};

//一元谓词
void test(){
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    //查找大于20的数  第三个参数是函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), CreateThen20()); // CreateThen20()是一个匿名对象
    if (it != v.end()) {
        cout<<"找到大于20的数字为："<<*it<<endl;
    }
    
}

class myCompare {
public:
    bool operator()(int v1,int v2){
        return v1>v2;
    }
};

//二元谓词
void test11(){
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    sort(v.begin(), v.end(), myCompare());//使用二元谓词    myCompare()是匿名对象
    
    //匿名函数  lambda表达式  [](){};  ：[]：lambda标识符  （）：参数  {}：实现
    for_each(v.begin(), v.end(), [](int val){cout<<val<<" ";});
    cout<<endl;
}

//内建函数
void tee(){
    //取反仿函数  template<class T> T negate<T>
    negate<int> n;
    cout<<n(12)<<endl;
    
    //加法仿函数  template<class T> T plus<T>
    plus<int> p;
    cout<<"1+1="<<p(1,1)<<endl;
    
    
    
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    sort(v.begin(), v.end(), greater<int>());//从大到小   系统提供的仿函数 大于
    for_each(v.begin(), v.end(), [](int val){cout<<val<<" ";});
    cout<<endl;
    sort(v.begin(), v.end(), less<int>());//从小到大
    for_each(v.begin(), v.end(), [](int val){cout<<val<<" ";});
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
//    test();
//    test11();
    tee();
    return 0;
}
