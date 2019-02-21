//
//  Monster.cpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Monster.hpp"
#include "Hero.hpp"

Monster::Monster(){
    this->m_Hp = 300;
    this->m_Atk = 70;
    this->m_Def = 40;
    this->m_Hold = false;
    this->m_Name = "魔鬼";
}

void Monster::attack(Hero * hero){
    if (this->m_Hold) {
        cout<<this->m_Name<<"被定身了，本回合无法攻击"<<endl;
        return;
    }
    //攻击英雄
    int damage = (this->m_Atk - hero->m_def) > 0? this->m_Atk - hero->m_def : 1;
    hero->m_Hp -=damage;
    cout<<this->m_Name<<"攻击了"<<hero->m_Name<<"造成了伤害："<<damage<<endl;
}
