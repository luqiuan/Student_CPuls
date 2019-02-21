//
//  main.cpp
//  演讲比赛实战
//
//  Created by luqiuan on 2019/2/21.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Header.h"
using namespace std;

//比较
bool compareAvr(Contestanter con1,Contestanter con2){
    return con1.getAverage() > con2.getAverage();
}

//生成一个随机序列的vector
void createRandList(vector<int> &v,int size){
    for (int i = 0; i < size; i++) {
        v.push_back(i);
    }
    //产生随机数
    random_shuffle(v.begin(), v.end());
}

void startGame(Contestanter &con){
    //开始打分 60~100
    vector<int> scoreList;
    int total = 0;
    for (int i = 0; i < 10; i++) {
        int score = rand() % 40 + 61;//60~100
        scoreList.push_back(score);
        total += score;
    }
    //排序
    sort(scoreList.begin(), scoreList.end());
    total -= *(scoreList.begin());
    total -= *(--scoreList.end());
    scoreList.erase(scoreList.begin());
    scoreList.erase(--scoreList.end());
    con.setAverage(total/scoreList.size());
}

void createPerson(vector<Contestanter> &conList,int total){
    //创建24个选手
    for (int i = 0; i < total; i ++) {
        string name = "选手";
        name += to_string(i+1);
        Contestanter cons(name);
        conList.push_back(cons);
    }
}

//随机分组
void createGroup(const vector<Contestanter> &playerList,multimap<int,Contestanter> &mapList,int count){
    vector<int> randList;
    createRandList(randList,playerList.size());
    int vlaue = playerList.size()/count;//每组人数
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < vlaue; j++) {
            int index = randList[i*vlaue+j];
            Contestanter con = playerList[index];
            mapList.insert(make_pair(i, con));
        }
    }
}

void delePlayer(int group,vector<Contestanter> &newList,multimap<int,Contestanter> &mapList){
    //淘汰每组z排名靠后的三名
    multimap<int,Contestanter>::iterator it = mapList.find(group);
    multimap<int,Contestanter>::size_type count = mapList.count(group);
    vector<Contestanter> conList;
    for (; count > 0; it++,count--) {
        conList.push_back((*it).second);
    }
    //排序
//    sort(conList.begin(), conList.end(), [](Contestanter con1,Contestanter con2){return con1.getAverage() > con2.getAverage();});//用lambdab表达式
        sort(conList.begin(), conList.end(), compareAvr);//用函数参数
    conList.erase(--conList.end());
    conList.erase(--conList.end());
    conList.erase(--conList.end());
    newList.insert(newList.end(), conList.begin(),conList.end());
}

//第一轮比赛返回剩下的选手
vector<Contestanter> firstGame(multimap<int,Contestanter> &mapList){
    
    for (multimap<int,Contestanter>::iterator it = mapList.begin(); it!= mapList.end(); it++) {
        startGame((*it).second);
    }
    
    vector<Contestanter> newList;//第一轮之后剩余的选手
    for (int i = 0; i < 4; i ++) {
        delePlayer(i, newList, mapList);
    }
    cout<<"-----第一轮之后剩余的选手-----"<<endl;
    for_each(newList.begin(), newList.end(),[](Contestanter con){con.show();});
    return newList;
}

//第二轮比赛  返回剩下选手
vector<Contestanter> secondGame(multimap<int,Contestanter> &mapList){
    
    for (multimap<int,Contestanter>::iterator it = mapList.begin(); it!= mapList.end(); it++) {
        startGame((*it).second);
    }
    
    vector<Contestanter> newList;//第一轮之后剩余的选手
    for (int i = 0; i < 2; i ++) {
        delePlayer(i, newList, mapList);
    }
    cout<<"-----第二轮之后剩余的选手-----"<<endl;
    for_each(newList.begin(), newList.end(),[](Contestanter con){con.show();});
    return newList;
}

//第三轮比赛  返回剩下选手
vector<Contestanter> thirdGame(multimap<int,Contestanter> &mapList){
    
    for (multimap<int,Contestanter>::iterator it = mapList.begin(); it!= mapList.end(); it++) {
        startGame((*it).second);
    }
    
    vector<Contestanter> newList;//第一轮之后剩余的选手
    for (int i = 0; i < 1; i ++) {
        delePlayer(i, newList, mapList);
    }
    cout<<"-----第三轮之后剩余的选手-----"<<endl;
    for_each(newList.begin(), newList.end(),[](Contestanter con){con.show();});
    return newList;
}

int main(int argc, const char * argv[]) {
    vector<Contestanter> playerList;
    //创建选手
    createPerson(playerList,24);
    //第一轮  分为4组每组6个人  使用multimap
    multimap<int, Contestanter> mapList;
    createGroup(playerList, mapList, 4);
    //开始第一轮比赛
    vector<Contestanter> secondList = firstGame(mapList);
    multimap<int, Contestanter> secondMapList;
    createGroup(secondList, secondMapList, 2);
    //开始第2轮比赛
    vector<Contestanter> thirdList = secondGame(secondMapList);
    multimap<int, Contestanter> thirdMapList;
    createGroup(thirdList, thirdMapList, 1);
    //开始第3轮比赛
    vector<Contestanter> finallList = thirdGame(thirdMapList);
    
    
    
    
//    for_each(mapList.begin(), mapList.end(), [](pair<int, Contestanter>pa){cout<<pa.first+1<<"组:";pa.second.show();});
    
    
    return 0;
}
