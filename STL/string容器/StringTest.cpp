//
//  StringTest.cpp
//  STL
//
//  Created by luqiuan on 2019/2/19.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "StringTest.hpp"

template <class T>
void show(T str){
    cout<<"打印："<<str<<endl;
}

void test(){
    //构造函数
    string str = string();
    str = string("陆求安");
    show(str);
    char *chlist = "哈哈哈哈哈哈哈";
    str = string(chlist);
    show(str);
    string str1 = str;
    show(str);
    string str2 = string(3,'r');//用三个r初始化：rrr
    show(str2);
    
    //基本赋值
    str2 = 'd';
    show(str2);
    str2.assign("qweasd",3);//将qweasd前三个赋值给str2
    show(str2);
    
}

//存取字符串
void test4(){
    string str = "hello world";
    for (int i = 0; i < str.size(); i ++) {
//        show(str[i]); //中括号访问需注意越界 ，不会抛出异常
        show(str.at(i));//使用at越界后会抛出异常
    }
}

//拼接操作  查找
void test5(){
    string str = " hello world lo ";
    string str1 = " go go ";
    str += str1;
    show(str);
    str1.append("我爱中国");
    show(str1);
    
    //查找 find
    int pos = str.find("lo"); //找不到返回的是-1
    show(pos);
    
    int pos2 = str.rfind("lo");
    show(pos2);
    
    //替换，从第二个位置开始的连续三个字符替换为"999"
    str.replace(2, 3, "999");
    show(str);
    
    //字符串比较
    str1 = "ab";
    str = "ac";
    int res = str1.compare(str);
    if (res == 0) {
        show("相等");
    }else if (res == 1){
        show("str1大于str");
    }else{
        show("str1小于str");
    }
    
    //子字符串
    string email = "luqiuann@qq.com";
    int po = email.find("@");
    string name = email.substr(0,po);
    show(name);
    
    //删除和插入
    str = "luqiuan";
    str.insert(1, "oo");
    show(str);
    str.erase(1,2);
    show(str);
    
    
    //c字符串和string 转换
    //string->C字符串
    string stt = "陆求安";
    const char * cstr = stt.c_str();
    //C字符串->string
    char *chlist = "哈哈哈";
    string srrr(chlist);
    //const char *隐式转换为 string
    //string不能隐式转换为const char *
}


void stringTest(){
    cout<<"---------string类学习---------"<<endl;
//    test4();
    test5();
    cout<<"---------string类学习---------"<<endl;
}
