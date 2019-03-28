//
//  Student.cpp
//  学生信息管理系统
//
//  Created by luqiuan on 2019/2/26.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Student.hpp"

//构造函数
Student::Student()
{
     Sort = 0;
}

void Student::SetInfo(string N, int A)//设置学生的信息(设置姓名、年龄)
{
     Name = N;
     Age = A;
}

void Student::SetNo(int N)//设置学生的编号
{
     No = N;
}

void Student::SetScore(int C, int M, int E)//设置学生的成绩(C++、高数、英语)
{
     Cpp = C;
     Math = M;
     English = E;
}
  
void Student::CountTotal()//计算总分
{
     Total = Cpp + Math + English;
}

void Student::CountAve()//计算学生的平均分
{
     Ave = Total / 3;
}

void Student::SetS(int s)//设置序号(用于排名)
{
     Sort = s;
}

void Student::GetInfo(string *pN, int *pA)//得到学生的信息(得到姓名、年龄)
{
     *pN = Name;
     *pA = Age;
}

int Student::GetNo()//得到学生的编号
{
     return No;
}

//得到学生的分数(C++ 高数 英语 总分 平均分)
void Student::GetScore(int *pC, int *pM, int *pE, int *pT, int *pA)
{
     *pC = Cpp;//得到C++成绩
     *pM = Math;//得到数学成绩
     *pE = English;//得到英语成绩
     *pT = Total;//得到总分
     *pA = Ave;//得到平均分
}

int Student::GetS()//得到序号(用于排名)
{
     return Sort;
}

