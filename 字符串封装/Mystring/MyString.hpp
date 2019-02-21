//
//  MyString.hpp
//  字符串封装
//
//  Created by luqiuan on 2019/1/29.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include <iostream>
using namespace std;
class MyString {
    friend ostream& operator<<(ostream &cout ,MyString &str);
    friend istream& operator>>(istream &cin ,MyString &str);
public:
    MyString(const char *str);
    MyString(const MyString&str);
    ~MyString();
    void displayString();
    int getSize();
    
    MyString& operator+(const MyString &str);
    MyString& operator+(const char *str);
    MyString& operator=(const MyString &str);
    MyString& operator=(const char *str);
    char &  operator[](int index);
    
    
private:
    char *pString;
    size_t m_Size;
};

