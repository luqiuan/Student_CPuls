//
//  MyString.cpp
//  字符串封装
//
//  Created by luqiuan on 2019/1/29.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "MyString.hpp"
MyString::MyString(const char *str){
    this->pString = new char[strlen(str)+1];
    strcpy(this->pString, str);
    this->m_Size = strlen(str);
}

MyString::MyString(const MyString &str){
    this->pString = new char[str.m_Size + 1];
    strcpy(this->pString, str.pString);
    this->m_Size = str.m_Size;
}

MyString::~MyString(){
    if (this->pString != NULL) {
        delete [] this->pString;
        this->pString = NULL;
    }
}

void MyString::displayString(){
    cout<<"值为：";
    for (int i = 0; i <this->m_Size; i++) {
        cout<<this->pString[i];
    }
    cout<<endl;
}

int MyString::getSize(){
    return this->m_Size;
}

ostream& operator<<(ostream &cout ,MyString &str){
    str.displayString();
    return cout;
}

istream& operator>>(istream &cin ,MyString &str){
    if (str.pString != NULL) {
        delete [] str.pString;
        str.pString = NULL;
        str.m_Size = 0;
    }
    char ch[4024];
    cin>>ch;
    cout<<"原始"<<ch<<endl;
    str.pString = new char[strlen(ch)+1];
    strcpy(str.pString, ch);
    str.m_Size = strlen(ch);
    return cin;
}

MyString &MyString::operator=(const MyString &str){
    if (this->pString != NULL) {
        delete [] this->pString;
        this->pString = NULL;
    }
    this->pString = new char[strlen(str.pString)+1];
    this->m_Size = strlen(str.pString);
    strcpy(this->pString, str.pString);
    return *this;
}

MyString &MyString::operator=(const char *str){
    if (this->pString != NULL) {
        delete [] this->pString;
        this->pString = NULL;
    }
    this->pString = new char[strlen(str)+1];
    this->m_Size = strlen(str);
    strcpy(this->pString, str);
    return *this;
}


MyString& MyString::operator+(const MyString &str){
    strcat(this->pString, str.pString);
    this->m_Size = strlen(this->pString);
    return *this;
}

MyString& MyString::operator+(const char *str){
    strcat(this->pString, str);
    this->m_Size = strlen(this->pString);
    return *this;
}

char& MyString::operator[](int index){
    return this->pString[index];
}
