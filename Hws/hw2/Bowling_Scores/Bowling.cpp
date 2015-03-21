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
    for (int i=0;i<10;i++){
        frames[i] = Frame();
    }
	setFrames();
}

Bowling::Bowling(string aFirstName, string aLastName, vector <int> aScores){
    firstName = aFirstName;
    lastName = aLastName;
	scores.clear();
    scores = aScores;
	cout << "set me!" << endl;
    setFrames();
	cout << "I'm set!" << endl;
}

void Bowling::setFrames(){
    int j=0;
    int size = scores.size();
    bool frame2 = false;
	bool done = false;
	int i=0;
    //for (int i=0;i<size;i++){
	while (i<size && !done){
		cout << "hi i is: " << i << endl; 
        cout << "hi j is: " << j << endl; 
		if (j == 9){
            if (size - i == 3){
				cout << "hit on size-3: " << endl; 
                frames[i] = Frame(scores[size-3], scores[size-2], scores[size-1]);
				j++;
            }
            else if(size - i == 2){
				cout << "hit on size-2: " << endl; 
                frames[i]= Frame(scores[size-2], scores[size-1], -1);
				j++;
            }
            else{
                cout << "size is: " << size - i << endl;
            }
			done = true;
        }
        else if (scores[i] == 10 && !done && !frame2){
            frames[i] = Frame();
            frame2 = false;
            j++;
        }
        else if (frame2 && !done){
            frames[i] = Frame(scores[i-1], scores[i]);
            frame2 = false;
            j++;
        }
        else{
            frame2 = true;
        }
		i++;
		cout << "got to the end" <<endl;
    }
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

void Bowling::setFrame(Frame aFrame, int i){
	frames[i] = aFrame;
}

Frame Bowling::getFrame(int i){
	return frames[i];
}

