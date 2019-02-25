//
//  main.cpp
//  自定义算法
//
//  Created by fzkjcs on 2019/2/22.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkTest.hpp"
#include "combineList.hpp"
using namespace std;

//用哈希算法 找出一个字符串中 第一个出现一次的字母
void find(){
    char *chList = "oidsfhhhhdkashkhio";
    
    //一个char占一个字节，一个字节有八个byte位，所以char有256中可能，我们可以定义一个长度为256的数组arr,arr的下标表示ascll码，对应的值表示ascll吗对应字符出现的次数，之后我们只需要根据对应的字符的ascll码获取次数就可
    int arr[256] = {0};
    
    char *p = chList;
    while ((*p) != NULL) {
        arr[*(p++)]++;
    }
    
    p = chList;
    while ((*p) != NULL) {
        if (arr[*p] == 1) {
            cout<<"找到了:"<<*p<<endl;
            break;
        }
        p++;
    }
}

int main(int argc, const char * argv[]) {
    find();
    return 0;
}
