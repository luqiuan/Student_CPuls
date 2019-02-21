//
//  main.cpp
//  继承
//
//  Created by luqiuan on 2019/1/29.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
using namespace std;

class Base {
    
public:
    Base();
    int a;
    int b;
};

class Son :public Base{
    
public:
    Son();
    int c;
};

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    

    cout<<endl;
    cout<<endl;
    cout<<endl;
    

    return 0;
}


void snike(){
    char game[20][20];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i==0 || j==0||i == 19 ||j==19) {
                game[i][j] = '8';
            }else{
                game[i][j] = ' ';
            }
        }
    }
    
    for (int i = 0; i < 20; i++) {
        cout<<endl;
        for (int j = 0; j < 20; j++) {
            cout<<game[i][j]<<' ';
        }
    }
}
