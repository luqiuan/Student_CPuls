//
//  Animal.cpp
//  类型转换
//
//  Created by luqiuan on 2019/2/15.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Animal.hpp"

class Animal {
public:
    
};

class Cat: public Animal {
public:
    
};

void test(){
    //向上强制类型转换 子类对象强转为父类对象
    //安全的，因为子类分配的空间大于父类指针指向的空间，指针不会越界
    Cat *cat = new Cat();
    Animal *animal = (Animal *)cat;
    
    //向下强制类型转换 父类对象强制转换为子类对象
    //不安全的，因为父类分配的空间小于子类指针指向的空间，指针可能会越界
    Animal *animal1 = new Animal();
    Cat *cat1 = (Cat *)animal1;
    
    //如果发生了多态，那类型转换总是安全的
    Animal *an = new Cat();
    Cat *cat11 = (Cat *)an;
}
