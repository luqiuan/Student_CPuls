//
//  Contestanter.cpp
//  演讲比赛实战
//
//  Created by luqiuan on 2019/2/21.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Contestanter.hpp"


Contestanter::Contestanter(){
    this->getName() = "";
    this->average = 0;
}

Contestanter::Contestanter(string name){
    this->name = name;
    this->average = 0;
}

void Contestanter::setAverage(int avg){
    this->average = avg;
}

int Contestanter::getAverage(){
    return this->average;
}

string Contestanter::getName(){
    return this->name;
}

void Contestanter::show(){
    cout<<"我叫"<<this->name<<",我的平均分是："<<this->average<<"分。"<<endl;
}

