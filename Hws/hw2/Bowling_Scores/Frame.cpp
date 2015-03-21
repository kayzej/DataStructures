//
//  Frame.cpp
//  Bowling_Scores
//
//  Created by Jeffrey Kayzerman on 1/9/14.
//  Copyright (c) 2014 Jeffrey Kayzerman. All rights reserved.
//

#include "Frame.h"
#include <iostream>

using namespace std;

// Default Constructor is a strike
Frame::Frame(){
    bowl1=10;
    bowl2=0;
    bowl3=0;
    print1 = ' ';
    print2 = 'X';
	print3 = ' ';
}

Frame::Frame(int aBowl1, int aBowl2){
    bowl1 = aBowl1;
    bowl2 = aBowl2;
    bowl3 = 0;
	print3 = ' ';
    
    if (bowl1 == 10){
        print1 = ' ';
        print2 = 'X';
    }
    else if (bowl1 + bowl2 == 10){
        print1 = (char) bowl1;
        print2 = '/';
    }
    else {
        if (bowl1 == 0){
            print1 = '-';
        }
        else{
            print1 = (char) bowl1;
        }
    
        if (bowl2 == 0){
            print2 = '-';
        }
        else{
            print2 = (char) bowl2;
        }
    }
}

Frame::Frame(int aBowl1, int aBowl2, int aBowl3){
    bowl1 = aBowl1;
    bowl2 = aBowl2;
    bowl3 = aBowl3;
    
    if (bowl3 == 10){
        print3 = 'X';
    }
    else if(bowl3 == 0){
        print3 = '-';
    }
    else if (bowl3 == -1){
        print3 = ' ';
    }
    else{
        print3 = (char) bowl3;
    }
    
    if (bowl1 + bowl2 == 10){
        if (bowl1 == 0){
            print1 = '-';
        }
        else {
            print1 = (char) bowl1;
        }
        print2 = '/';
    }
    else {
        if (bowl1 == 0){
            print1 = '-';
        }
        else{
            print1 = (char) bowl1;
        }
        
        if (bowl2 == 0){
            print2 = '-';
        }
        else{
            print2 = (char) bowl2;
        }
    }
}

int Frame::getBowl1(){
    return bowl1;
}

int Frame::getBowl2(){
    return bowl2;
}

int Frame::getPrint1(){
    return print1;
}

int Frame::getPrint2(){
    return print2;
}

int Frame::getPrint3(){
    return print3;
}



