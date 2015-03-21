//
//  Bowling.cpp
//  Bowling_Scores
//
//  Created by Jeffrey Kayzerman on 1/4/14.
//  Copyright (c) 2014 Jeffrey Kayzerman. All rights reserved.
//

#include "Bowling.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Bowling::Bowling(){
    firstName = "";
    lastName = "";
    scores.clear();
    
    for (int i=0;i<frames.size();i++){
        frames.push_back(Frame());
    }
}

Bowling::Bowling(string aFirstName, string aLastName, vector <int> aScores){
    firstName = aFirstName;
    lastName = aLastName;
    scores = aScores;
    setFrames();
}

void Bowling::setFrames(){
    int j=0;
    long size = scores.size();
    bool frame2 = false;
    for (int i=0;i<size;i++){
        if (j == 9){
            if (size - i == 3){
                frames.push_back(Frame(scores[size-3], scores[size-2], scores[size-1]));
            }
            else if(size - i == 2){
                frames.push_back(Frame(scores[size-2], scores[size-1], -1));
            }
            else{
                cout << "huh?" << endl;
            }
        }
        else if (scores[i] == 10){
            frames.push_back(Frame());
            frame2 = false;
            j++;
        }
        else if (frame2){
            frames.push_back(Frame(scores[i-1], scores[i]));
            frame2 = false;
            j++;
        }
        else{
            frame2 = true;
        }
    }
}

vector<Frame> Bowling::getFrames(){
    return frames;
}

string Bowling::getFirstName(){
    return firstName;
}

string Bowling::getLastName(){
    return lastName;
}

int Bowling::get(int a){
    return scores[a];
}

void Bowling::setFirstName(string aFirstName){
    firstName = aFirstName;
}

void Bowling::setLastName(string aLastName){
    lastName = aLastName;
}

void Bowling::setI(int i, int a){
    scores[a] = a;
}

void Bowling::add(int a){
    scores.push_back(a);
}

void Bowling::subtract(){
    scores.pop_back();
}

