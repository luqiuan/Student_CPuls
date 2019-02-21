//
//  main.cpp
//  多态小游戏案例
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include "Hero.hpp"
#include "Monster.hpp"
//#include "Weapon.hpp"
#include "Knife.hpp"
#include "DragonSword.hpp"

void play(){
    Hero *hero = new Hero();
    Monster *monster = new Monster();

    //创建武器
    Weapon *nifi = new Knife;
    Weapon *dragon = new DragonSword();

    //让用户选择武器
    cout<<"请选择武器："<<endl;
    cout<<"1、赤手空拳"<<endl;
    cout<<"2、小刀"<<endl;
    cout<<"3、屠龙宝刀"<<endl;

    int oper;
    cin >> oper;
    switch (oper) {
        case 1:
        {
            cout<<"你真牛逼，你还是太年轻了"<<endl;
        }
            break;
        case 2:
        {
            cout<<"你选择了小刀"<<endl;
            hero->weapon = nifi;
        }
            break;
        case 3:
        {
            cout<<"你选择了屠龙宝刀"<<endl;
            hero->weapon = dragon;
        }
            break;
        default:
            break;
    }
    getchar();//输入缓冲区里有个回车。多获取一次值
    int round = 1;
    while (true) {
        getchar();
        cout<<"------当前是第"<<round<<"回合开始------"<<endl;
        if(hero->m_Hp <= 0){
            cout<<hero->m_Name<<"已牺牲,游戏结束！"<<endl;
            break;
        }
        hero->Attack(monster);

        if (monster->m_Hp <= 0) {
            cout<<"怪物"<<monster->m_Name<<"已死，游戏胜利"<<endl;
            break;
        }
        monster->attack(hero);

        if(hero->m_Hp <= 0){
            cout<<hero->m_Name<<"已牺牲,游戏结束！"<<endl;
            break;
        }
        cout<<hero->m_Name<<"剩余血量"<<hero->m_Hp<<endl;
        cout<<monster->m_Name<<"剩余血量"<<monster->m_Hp<<endl;
        round ++;
    }

    delete monster;
    delete hero;
    delete nifi;
    delete dragon;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    play();
    return 0;
}
