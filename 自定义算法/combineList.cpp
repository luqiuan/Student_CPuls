//
//  combineList.cpp
//  自定义算法
//
//  Created by fzkjcs on 2019/2/23.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "combineList.hpp"

#include <iostream>
#include <string>
using namespace std;

//将两个数组合并成一个有序数组
int list1[] = {1,5,9,2,4,98,33,33,101};
int list2[] = {11,3,8,7,14,0,98,99,88,33,55,22};

void show(int *list,int len){
    cout<<"打印:";
    for (int i = 0; i < len; i++) {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

//有序数组合并
void sort1(){
    int len = sizeof(list1)/sizeof(list1[0]);
    //先排序
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (list1[j] > list1[j+1]) {
                int tem = list1[j];
                list1[j] = list1[j+1];
                list1[j+1] = tem;
            }
        }
    }
    show(list1,len);
    
    len = sizeof(list2)/sizeof(list2[0]);
    //先排序
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (list2[j] > list2[j+1]) {
                int tem = list2[j];
                list2[j] = list2[j+1];
                list2[j+1] = tem;
            }
        }
    }
    show(list2,len);
}

//合并
void cmbin(){
    int len1 = sizeof(list1)/sizeof(list1[0]);
    int len2 = sizeof(list2)/sizeof(list2[0]);
    int newList[len2+len1];
    int big = len1+len2;//len2>len1? len2:len1;
    int poi1= 0,poi2 = 0,poi3 = 0;
    for (int i = 0; i < big; i++) {
        
        if (poi1 == len1) {
            for (int j = poi2; j<len2; j++) {
                newList[poi3++] = list2[j];
            }
            break;
        }
        if (poi2 == len2) {
            for (int j = poi1; j<len1; j++) {
                newList[poi3++] = list1[j];
            }
            break;
        }
        
        
        
        int a = list1[poi1];
        int b = list2[poi2];
        if (a<b) {
            cout<<poi3<<":"<<a<<endl;
            newList[poi3++] = a;
            poi1++;
        }else if(a == b){
            newList[poi3++] = a;
            newList[poi3++] = a;
            poi1++;
            poi2++;
        }else{
            cout<<poi3<<":"<<b<<endl;
            newList[poi3++] = b;
            poi2++;
        }
    }
    
    //    for (int i = poi1; i < len1; i++) {
    //        newList[poi3++] = list1[i];
    //    }
    show(newList,len1+len2);
}

void tezs(){
    int len = sizeof(list1)/sizeof(list1[0]);
    show(list1,len);
    len = sizeof(list2)/sizeof(list2[0]);
    show(list2,len);
    sort1();//排序
    cmbin();
}
