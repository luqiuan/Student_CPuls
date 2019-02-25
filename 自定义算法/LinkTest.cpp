//
//  LinkTest.cpp
//  自定义算法
//
//  Created by fzkjcs on 2019/2/23.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "LinkTest.hpp"
#include <iostream>
#include <string>
using namespace std;

//字符串反转
void string_reveser(string &str){
    int begin = 0;
    string::size_type end = str.size() - 1;
    for (string::size_type i = 0; begin < end; i++,end--,begin++) {
        char tem = str[begin];
        str[begin] = str[end];
        str[end] = tem;
    }
}

//链表反转
struct Node {
    string name;
    Node *next;
};

typedef Node* Link;

void createNode(Node * &node){
    Link head = node;
    for (int i = 0; i < 15; i++) {
        Link node = new Node();
        node->name = "LU"+to_string(i+1);
        head->next = node;
        head = node;
    }
}

//打印traverse
void showNode(Node * &head){
    Link node = head->next;
    cout<<"打印：";
    while (node) {
        cout<<node->name<<" ";
        node = node->next;
    }
    cout<<endl;
}

//反转 头插法
Node *  reversalNode(Node * head){
    Link node = head->next;
    Link newNode = new Node();
    Link temNode = (Link)malloc(sizeof(Node));
    while (node) {
        temNode = node->next;
        node->next = newNode->next;
        newNode->next = node;
        node = temNode;
    }
    return newNode;
}

//
//反转 就地反转
Node *  reversalNode11(Node * head){
    //head->1>2>3>4
    //head->2>1>3>4
    //head->3>2>1>4
    //head->4>3>2>1
    Link node = head->next;
    Link tem = node->next;
    while (tem) {
        node->next = tem->next;
        tem->next = head->next;
        head->next = tem;
        tem = node->next;
    }
    return head;
}

//反转  变换每个节点
Node *  reversalNode111(Node * head){
    Link node = head->next;
    Link tem = node->next;
    Link tem1 = NULL;
    while (node) {
        head->next = node;
        node->next = tem1;
        tem1 = node;
        if (!tem) {
            node = NULL;
            tem = NULL;
        }else{
            node = tem;
            tem = tem->next;
        }
    }
    return head;
}

void  test12() {
    string str = "abc978哈的";
    //    string_reveser(str);
    Link head;
    createNode(head);
    showNode(head);
    //反转
    Node *head1 = reversalNode111(head);
    showNode(head1);
}
