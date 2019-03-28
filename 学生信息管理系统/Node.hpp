//
//  Node.hpp
//  学生信息管理系统
//
//  Created by luqiuan on 2019/2/26.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <string>
using namespace std;
#include "Student.hpp"

class Node//结点类
{
public:
   void InputStudent();//输入学生信息
   void OutputStudent();//输出学生信息
   Node* AddStudent();//增加学生信息
   bool DeleteStudent();//删除学生信息
   void ChangeStudent();//修改学生信息
   void SearchStudent();//查找学生信息
   void SortCpp();//将C++成绩按照从大到小排序
   void SortMath();//将高数成绩按照从大到小排序
   void SortEnglish();//将英语成绩按照从大到小排序
   void SortTotal();//将总分按照从大到小排序
   void SetScort();//设置排名
   void ChangeNo(Node *p);//修改学生的学号
      
private:
        Student st;//数据域
        Node *pNext;//指针域
        Node *pHead;//头结点
};
typedef Node NODE;
typedef Node* PNODE;
/*
 NODE 相当于  Node
 PNODE 相当于 Node*
 */
