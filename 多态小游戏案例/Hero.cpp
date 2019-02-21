//
//  Hero.cpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Hero.hpp"
#include "Weapon.hpp"
#include "Monster.hpp"

Hero::Hero(){
    this->m_Hp = 500;
    this->m_Atk = 50;
    this->m_def = 50;
    this->m_Name = "周杰伦";
    this->weapon = NULL;
}

void Hero::EquipWeapon(Weapon *weapon)//装备武器
{
    this->weapon = weapon;
    cout<<"英雄："<<this->m_Name<<"装备了武器<<"<<this->weapon->m_Name<<">>"<<endl;
}

void Hero::Attack(Monster *monster)//攻击
{
    int damage = 0;
    int addHp = 0;
    bool isHold = false;
    bool isCirt = false;
    if (this->weapon == NULL) {
        damage = this->m_Atk;
    }else{
        //基础伤害
        damage = this->weapon->getBaseDamage()+this->m_Atk;
        //计算吸血
        addHp = this->weapon->getSuckBlood();
        //计算定身
        isHold = this->weapon->getHold();
        //计算是否暴击
        isCirt = this->weapon->getCrit();
    }
    if (isCirt) {
        damage = damage * 2;
        cout<<this->m_Name<<"的武器触发了暴击效果，怪物收到了双倍的伤害，伤害值："<<damage<<endl;
    }
    if (isHold) {
        cout<<this->m_Name<<"的武器触发了定身效果，怪物停止攻击一回合"<<endl;
    }
    if (addHp > 0) {
        cout<<this->m_Name<<"的武器触发了吸血效果，增加的血量为："<<addHp<<endl;
    }
    
    //攻击怪物
    monster->m_Hold = isHold;
    //计算真实伤害
    int trueDamage = (damage - monster->m_Def) > 0? damage - monster->m_Def:0;
    monster->m_Hp -= trueDamage;
    this->m_Hp += addHp;
    cout<<this->m_Name<<"攻击了敌人"<<monster->m_Name<<"造成了伤害："<<trueDamage<<endl;
}
