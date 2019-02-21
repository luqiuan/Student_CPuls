//
//  example.cpp
//  STL
//
//  Created by luqiuan on 2019/2/19.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "example.hpp"
#include <algorithm>

//十个评委给十个候选人打分，去掉一个最高和最低，求平均分

class Person {
public:
    Person(string name,int score){
        this->name = name;
        this->score = score;
    }
    
    string name;
    int score;
};

//随机数1~100
//int num = rand()%100 + 1;
int score(){
    deque<int> scoreList;//10个评分
//    cout<<"十个分数：";
    for (int i = 0; i < 10; i++) {
        int num = rand()%100 + 1;
//        cout<<num<<",";
        scoreList.push_front(num);
    }
//    cout<<endl;
    sort(scoreList.begin(), scoreList.end());
    scoreList.erase(scoreList.begin());
    scoreList.erase(scoreList.end());
    //求平均分
    int total = 0,avarage = 0;
//    cout<<"去除最高和最低后：";
    for (deque<int>::iterator it = scoreList.begin();it != scoreList.end();it++) {
        total += *it;
//        cout<<*it<<",";
    }
//    cout<<endl;
    avarage = total/scoreList.size();
    return avarage;
}

bool custom(Person per,Person per2){
    return per.score < per2.score;
}

void example(){
    vector<Person> perList;
    for (int i = 0; i < 10; i++) {
        Person *per = new Person("哈哈"+to_string(i),0);
        per->score = score();
        //开始打分
        perList.push_back(*per);
    }
    
    sort(perList.begin(), perList.end(), custom);
    
    for (vector<Person>::iterator it = perList.begin(); it != perList.end(); it ++) {
        cout<<"我叫"<<(*it).name<<" 我的平均跟是："<<(*it).score<<endl;
    }
    
}
