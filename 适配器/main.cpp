//
//  main.cpp
//  适配器
//
//  Created by luqiuan on 2019/2/21.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//第一步：绑定数据 bind2nd
//

class Print1 :public binary_function<int, int, void>{
public:
    void operator()(int val,int start) const {
        cout<<val+start<<endl;
    }
};


void t4es(){
    vector<int> v;
    for (int i = 0; i < 10; i ++) {
        v.push_back(i+1);
    }
    int num = 99;
    for_each(v.begin(), v.end(), bind2nd(Print1(),num));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    t4es();
    return 0;
}
