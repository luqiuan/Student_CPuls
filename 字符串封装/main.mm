//
//  main.m
//  字符串封装
//
//  Created by luqiuan on 2019/1/29.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "MyString.hpp"

void test();
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        test();
    }
    return 0;
}

void test(){
    MyString str("陆");
    str.displayString();
    MyString strr(str);
    strr.displayString();
    cout<<"长度:"<<strr.getSize()<<endl;
    cout<<str;
    
    MyString st1 = strr + str;
    st1+"中国过过过";
    cout<<st1;
    cout<<st1.getSize()<<endl;
    cout<<st1[1]<<endl;
    cin>>str;
    cout<<str;
    
    
//    MyString stt4 = str;
//    cout<<stt4;
//    stt4 = "陆求安";
//    cout<<stt4;
}
