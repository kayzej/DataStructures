//
//  Bowling.h
//  Bowling_Scores
//
//  Created by Jeffrey Kayzerman on 1/4/14.
//  Copyright (c) 2014 Jeffrey Kayzerman. All rights reserved.
//

#ifndef Bowling_Scores_Bowling_h
#define Bowling_Scores_Bowling_h


#include <string>
#include <vector>
#include "Frame.h"

using namespace std;

class Bowling {
public:
    Bowling();
    Bowling(string aFirstName, string aLastName, vector <int> aScores);
    
    // Accessors
    string getFirstName();
    string getLastName();
    int get(int a);
	Frame getFrame(int i);
    
    //Modifiers
    void setFirstName(string aFirst);
    void setLastName(string aLast);
    void setI(int i, int a);
    void add(int a);
    void subtract();
    void setFrames();
    void setFrame(Frame aFrame, int i);
	
private:
    string firstName;
    string lastName;
    vector<int> scores;
    Frame frames[10];
};


#endif