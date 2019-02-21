//
//  Cube.cpp
//  学习C++
//
//  Created by luqiuan on 2019/1/26.
//  Copyright © 2019 luqiuan. All rights reserved.
//

#include "Cube.hpp"
#include <string>

class Cube {

    
public:
    Cube():m_H(10),m_L(20),m_W(30){
    }
    
//    Cube(int h,int l,int w){
//        m_H = h;
//        m_L = l;
//        m_W = w;
//    }
    
    Cube(int h,int l,int w):m_H(h),m_L(l),m_W(w){}
    
    //拷贝构造函数
    Cube(const Cube &cube){
        
    }
    
    ~Cube(){
        cout<<"这是析构函数"<<endl;
    }
    
    void setL(int l){
        m_L = l;
    }
    int getL() const{
        return m_L;
    }
    void setH(int h){
        m_H = h;
    }
    int getH() const{
        return m_H;
    }
    void setW(int w){
        m_W = w;
    }
    int getW() const{
        return m_W;
    }
    
    void getCubeS(){
        cout<<"立方体的面积为："<<2 *(m_L * m_H +m_W * m_H +m_L * m_W )<<endl;
    }
    
    void getCubeV(){
        cout<<"立方体的面积为："<<m_L * m_H * m_W <<endl;
    }
    
    bool compareCube(Cube taget){
        if (taget.getH() == getH() && taget.getW() == getW() && taget.getL() == getL()) {
            return true;
        }
        return false;
    }
    
private:
    int m_W;
    int m_H;
    int m_L;
    
};

class SubCube:Cube{
    SubCube(){
        
    }
public:
    string name;
};

//判断两个立方体是否相等
bool compareCube(const Cube &c1,const Cube &c2){
    if (c1.getH() == c2.getH() && c1.getW() == c2.getW() && c1.getL() == c2.getL()) {
        return true;
    }
    return false;
}

void start1(){
    Cube cube;
    cube.setL(10);
    cube.setH(10);
    cube.setW(10);
    cube.getCubeS();
    cube.getCubeV();
    
    Cube b2;
    b2.setL(10);
    b2.setH(10);
    b2.setW(11);
    b2.getCubeS();
    b2.getCubeV();
    
    if (b2.compareCube(cube)) {
        cout<<"相等"<<endl;
    }else{
        cout<<"不相等"<<endl;
    }
    
    Cube b3;
    b3.getCubeS();
    b3.getCubeV();
    
    Cube b4 = Cube(2,2,2);
    b4.getCubeS();
    b4.getCubeV();
    
    Cube b5(3,3,3);
    b5.getCubeS();
    b5.getCubeV();
    
    
}
