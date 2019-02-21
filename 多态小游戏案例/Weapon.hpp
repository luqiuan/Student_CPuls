//
//  Weapon.hpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Weapon {
public:
    string m_Name;//武器名
    int m_BaseDamage;//伤害值
    
    //获取基础伤害
    virtual int getBaseDamage() = 0;
    //获取吸血
    virtual int getSuckBlood() = 0;
    //获取是否定身
    virtual bool getHold() = 0;
    //获取是否暴击
    virtual bool getCrit() = 0;
};
