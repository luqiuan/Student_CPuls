//
//  Student.hpp
//  学生信息管理系统
//
//  Created by luqiuan on 2019/2/26.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <string>
using namespace std;

class Student//学生类
{
public:
    
    Student();//构造函数
    void SetInfo(string N, int A);//设置学生的信息(设置姓名、年龄)
    void SetNo(int N);//设置学生的编号
    void SetScore(int C, int M, int E);//设置学生的成绩(C++、高数、英语)
    void CountTotal();//计算总分
    void CountAve();//计算平均分
    void SetS(int S);//设置序号(用于排名)
    void GetInfo(string *pN, int *pA);//得到学生的信息(得到姓名、年龄)
    int GetNo();//得到学生的编号
    
    //得到学生的分数(C++ 高数 英语 总分 平均分)
    void GetScore(int *pC, int *pM, int *pE, int *pT, int *pA);
    int GetS();//得到序号(用于排名)
    
private:
    int len;          //学生的人数
    string Name;     //姓名
    int Age;         //年龄
    int No;          //学号
    int Cpp;         //C++成绩
    int Math;       //高数成绩
    int English;    //英语成绩
    int Total;     //总分
    float Ave;      //平均分
    int Sort;     //排名
};

