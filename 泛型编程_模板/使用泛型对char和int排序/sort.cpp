//
//  sort.cpp
//  泛型编程_模板
//
//  Created by luqiuan on 2019/2/18.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "sort.hpp"


//使用模板实现int和char的选择排序
void sort1(int arr[], int len){
    for (int j = 0; j < len - 1; j++) {
        int min = j;
        for (int i = j + 1;i < len ; i ++ ) {
            if (arr[min] > arr[i]) {
                min = i;
            }
        }
        if (arr[j] > arr[min]) {
            int tem = arr[min];
            arr[min] = arr[j];
            arr[j] = tem;
        }
    }
}

template <typename T>
void display(T arr[],int len){
    cout<<"---------------------"<<endl;
    for (int i = 0; i < len; i ++) {
        cout<<arr[i]<<"、";
    }
    cout<<endl;
    cout<<"---------------------"<<endl;
}

template <typename T>
void newSwap(T &a, T &b) {
    T tem = a;
    a = b;
    b = tem;
}

template <class T>
void newSort(T arr[], int len){
    for (int j = 0; j < len - 1; j++) {
        int min = j;
        for (int i = j + 1;i < len ; i ++ ) {
            if (arr[min] > arr[i]) {
                min = i;
            }
        }
        if (arr[j] > arr[min]) {
            newSwap(arr[j], arr[min]);
        }
    }
}

void test(){
//    int ch[] = {2,77,88,7,8,98,33,45,1,34,55};
    char ch[] = {'b','y','z','s','a','d','q','v'};
    int o = sizeof(ch)/sizeof(ch[0]);
    cout<<o<<endl;
//    sort1(arr,o);
    newSort(ch, o);
    display(ch, o);
}
