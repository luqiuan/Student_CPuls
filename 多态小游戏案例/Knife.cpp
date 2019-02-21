//
//  Knife.cpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Knife.hpp"


Knife::Knife(){
    this->m_BaseDamage = 10;
    this->m_Name = "小刀";
}
//获取基础伤害
int Knife::getBaseDamage(){
    return this->m_BaseDamage;
}
//获取吸血
int Knife::getSuckBlood(){
    return 0;
}
//获取是否定身
bool Knife::getHold(){
    return false;
}
//获取是否暴击
bool Knife::getCrit(){
    return false;
}
