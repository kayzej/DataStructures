//
//  main.cpp
//  Bowling_Scores
//
//  Created by Jeffrey Kayzerman on 1/4/14.
//  Copyright (c) 2014 Jeffrey Kayzerman. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Bowling.h"
#include "Frame.h"

using namespace std;

int main(int argc, const char * argv[])
{

    if (argc !=3) {
        cerr << "Usage: " << argv[0] << " text-file\n";
        return 1;
    }
    
    // Open the input file and ensure it opened properly
    ifstream in_file(argv[1]);
    if (!in_file){
        cerr << "Can not open the input file " << argv[1] << "\n";
        return 1;
    }
    
    // Open the output file and ensure it opened properly
    ofstream out_file(argv[2]);
    if (!out_file){
        cerr << "Error opening output file" << argv[2] << "\n";
        return 1;
    }
    
    vector <Bowling> players;
    string firstName;
    string lastName;
    int in;
    vector <int> temp_scores;
    bool extra = false;
    int max_name = 0;
    int name_length = 0;
    int j=0;
    
    while (!in_file.eof()){
        
        cout << "players: " << players.size() << endl;
        
        in_file >> firstName >> lastName;
		
		cout << "first name: " << firstName << " last name: " << lastName << endl;
        
        name_length = firstName.length() + lastName.length();
        
        while (in_file.peek() != '\n' && !in_file.eof()){
            in_file >> in;
            temp_scores.push_back(in);
        }
        cout << "hello world!" << endl;
        
		if(!in_file.eof()){
			cout << "so pushy!" << endl;
            players.push_back(Bowling(firstName, lastName, temp_scores));
            cout << "still pushy!" << endl;
			if (name_length > max_name){
                max_name = name_length;
            }
			
        }
        
        temp_scores.clear();
		
		cout << "hello again world!" <<endl;
    }
    
    for (int i=0; i<players.size();i++){
        cout << players[i].getFirstName() << ' ' << players[i].getLastName() << ' ' << i << ' ' << players[i].get(0) << ' ' << players[i].get(1) << endl;
        
  		//players[i].setFrames();

        for (int j=0; j<9; j++){
            out_file << ' ' << players[i].getFrame(j).getPrint1() << ' ' << players[i].getFrame(j).getPrint2();
        }
		
	    out_file << ' ' << players[i].getFrame(9).getPrint1() << ' ' << players[i].getFrame(9).getPrint2() << ' ' << players[i].getFrame(9).getPrint3() << endl;
	}
}

