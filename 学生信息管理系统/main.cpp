//
//  main.cpp
//  学生信息管理系统
//
//  Created by luqiuan on 2019/2/26.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include "Node.hpp"
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "穷Hello, World!\n";
    
    PNODE node = new Node();
    node->InputStudent();
    node->OutputStudent();
//    Node
    return 0;
}
