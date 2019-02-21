//
//  DragonSword.hpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

//屠龙刀


class Weapon;

class DragonSword : public Weapon {
public:
    DragonSword();
    //获取基础伤害
    virtual int getBaseDamage();
    //获取吸血
    virtual int getSuckBlood();
    //获取是否定身
    virtual bool getHold();
    //获取是否暴击
    virtual bool getCrit();
    
    
    int suckRate;//吸血力
    int holdRate;//定身力
    int cirtRate;//暴击力
    
    //传入概率，判断是否触发
    bool isTrigger(int rate);
};
