//
//  Hero.hpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Weapon;
class Monster;

class Hero {
public:
    Hero();
    
    string m_Name;
    int m_Atk;//攻击力
    int m_def;//防御力
    int m_Hp;//血量
    
    Weapon *weapon;//武器
    
    void EquipWeapon(Weapon *weapon);//装备武器
    void Attack(Monster *monster);//攻击
};
