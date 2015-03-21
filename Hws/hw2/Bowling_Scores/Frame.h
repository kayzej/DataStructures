//
//  Frame.h
//  Bowling_Scores
//
//  Created by Jeffrey Kayzerman on 1/9/14.
//  Copyright (c) 2014 Jeffrey Kayzerman. All rights reserved.
//

#ifndef Bowling_Scores_Frame_h
#define Bowling_Scores_Frame_h


#include <string>
#include <vector>

using namespace std;

class Frame {
public:
    Frame();
    Frame(int aBowl1, int aBowl2);
    Frame(int aBowl1, int aBowl2, int aBowl3);
    
    // Accessors
    int getBowl1();
    int getBowl2();
    int getPrint1();
    int getPrint2();
    int getPrint3();
    
    //Modifiers
    void setBowl1(int b1);
    void setBowl2(int b2);
    void setType(char x);
    
private:
    int bowl1;
    int bowl2;
    int bowl3;
    char print1;
    char print2;
    char print3;
};


#endif