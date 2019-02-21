//
//  Contestanter.hpp
//  演讲比赛实战
//
//  Created by luqiuan on 2019/2/21.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

class Contestanter {
private:
    string name;
    int average;
public:
    Contestanter();
    Contestanter(string name);
    void setAverage(int avg);
    int getAverage();
    string getName();
    void show();
};
