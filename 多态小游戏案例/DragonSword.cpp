//
//  DragonSword.cpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Weapon.hpp"

#include "DragonSword.hpp"
DragonSword::DragonSword(){
    this->m_BaseDamage = 20;
    this->m_Name = "屠龙宝刀";
    this->cirtRate = 35;
    this->holdRate = 30;
    this->suckRate = 20;
}
//获取基础伤害
int DragonSword::getBaseDamage(){
    return this->m_BaseDamage;
}
//获取吸血
int DragonSword::getSuckBlood(){
    if (isTrigger(suckRate)) {
        return this->m_BaseDamage * 0.5;//按照武器基础伤害一半吸血
    }
    return 0;
}
//获取是否定身
bool DragonSword::getHold(){
    if (isTrigger(holdRate)) {
        return true;
    }
    return false;
}
//获取是否暴击
bool DragonSword::getCrit(){
    if (isTrigger(cirtRate)) {
        return true;
    }
    return false;
}

//传入概率，判断是否触发
bool DragonSword::isTrigger(int rate){
    //通过isTrigger判断是否触发特效
    //随机数1~100
    int num = rand()%100 + 1;
    if (num < rate) {
        return true;
    }
    return false;
}
