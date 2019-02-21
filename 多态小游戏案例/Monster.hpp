//
//  Monster.hpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Hero;

class Monster {
public:
    Monster();
    
    string m_Name;
    int m_Hp;
    int m_Atk;
    int m_Def;
    
    bool m_Hold;
    
    void attack(Hero * hero);
};
