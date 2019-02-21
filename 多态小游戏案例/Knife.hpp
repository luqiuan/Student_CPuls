//
//  Knife.hpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Weapon.hpp"

class Knife : public Weapon  {
public:
    Knife();
    //获取基础伤害
    virtual int getBaseDamage();
    //获取吸血
    virtual int getSuckBlood();
    //获取是否定身
    virtual bool getHold();
    //获取是否暴击
    virtual bool getCrit();
};
