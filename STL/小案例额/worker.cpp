//
//  worker.cpp
//  STL
//
//  Created by luqiuan on 2019/2/21.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "worker.hpp"

enum{YanFa,Renli,Xingzheng};

class Worker {
public:
    string name;
    int gongzi;
    
    Worker(string name,int gongzi){
        this->name = name;
        this->gongzi= gongzi;
    }
};

void creatWork(vector<Worker> &woList){
    string namelist = "ABCDEFG";
    for (int i = 0; i < namelist.size(); i ++) {
        string name = "员工"; name += namelist[i];
        int gongzi = rand() % 10000 + 10000;
        Worker *worker = new Worker(name,gongzi);
        woList.push_back(*worker);
    }
}

void createPartment(vector<Worker> &woList,multimap<int, Worker> &partList){
    for (vector<Worker>::iterator it = woList.begin(); it != woList.end(); it ++) {
        int part = rand()%3;
        partList.insert(make_pair(part, *it));
    }
}

void showDetail(multimap<int, Worker> &partList){
//    for (multimap<int, Worker>::iterator it = partList.begin(); it != partList.end(); it ++) {
//        cout<<(*it).second.name<<" 部门："<<(*it).first+1<<" 工资:"<<(*it).second.gongzi<<endl;
//    }
    
    multimap<int, Worker>::iterator it = partList.find(YanFa);
    int num = partList.count(YanFa);
    int index = 0;
    for (; index < num; index ++,it++) {
        cout<<(*it).second.name<<" 部门："<<(*it).first+1<<" 工资:"<<(*it).second.gongzi<<endl;
    }
    
    it = partList.find(Renli);
    num = partList.count(Renli);
    index = 0;
    for (; index < num; index ++,it++) {
        cout<<(*it).second.name<<" 部门："<<(*it).first+1<<" 工资:"<<(*it).second.gongzi<<endl;
    }
    
    it = partList.find(Xingzheng);
    num = partList.count(Xingzheng);
    index = 0;
    for (; index < num; index ++,it++) {
        cout<<(*it).second.name<<" 部门："<<(*it).first+1<<" 工资:"<<(*it).second.gongzi<<endl;
    }
}

void workertest(){
    
    vector<Worker> workList;
    multimap<int, Worker> partList;
    
    //创建员工
    creatWork(workList);
    //创建部门
    createPartment(workList,partList);
    //显示部门
    showDetail(partList);
}
