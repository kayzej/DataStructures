#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

int main(int argc, char* argv[]) {
    // Using the convention set by the Lectures to check that the user inputted
    // the correct number of arguments
    if (argc !=5) {
        cerr << "Usage: " << argv[0] << " text-file\n";
        return 1;
    }
    
    // storing the lenght argument provided as an integer
    int length = atoi(argv[3]);
    
    
    // Open the input file and ensure it opened properly
    ifstream txt_file(argv[1]);
    if (!txt_file){
        cerr << "Can not open the input file " << argv[1] << "\n";
        return 1;
    }
    
    // Open the output file and ensure it opened properly
    ofstream out_file;
    out_file.open (argv[2]);
    if (!out_file){
        cerr << "Error opening output file" << argv[2] << "\n";
        return 1;
    }
    
    // Writing the first line of hyphens to the file
    // storing my hyphens string for top and bot of file
    const string hyphens(length + 4, '-');
    out_file << hyphens << "\n" << "| ";
    
    // Storing all the strings in an vector to loop through later
    // (derp what else are vectors for derp)
    vector<string> input;
    string input_string;
    while (txt_file >> input_string){
        if (input_string != " "){
            input.push_back(input_string);
        }
    }
    
    if (!(strcmp(argv[4], "flush_left"))){
        
        // Using the variable space_left to keep track of when I hit the end
        int space_left = length;
        
        // Loop through the vector of all the strings
        for (int i=0; i<input.size(); i++){
            
            // Calculating space remaining not including a space which comes later
            space_left -= input[i].length();

            // This means that the next element in the array needs to go on a new line
            if (space_left < 0){
                string spaces(input[i].length() + space_left, ' ');
                out_file << spaces << " |\n| ";
                space_left = length - input[i].length();
                out_file << input[i];
                if (space_left > 0) {
                    out_file << " ";
                    space_left -=1;
                }
            }
            else if(space_left == 0){
                out_file << input[i] << " |\n| ";
                space_left = length;
            }
            else{
                out_file << input[i] << " ";
                space_left -= 1;
            }
        }
        if (space_left > 0){
            string spaces(space_left, ' ');
            out_file << spaces;
        }
        out_file << " |\n";
    }
    else if (!(strcmp(argv[4], "flush_right"))){
        // Using the variable space_left to keep track of when I hit the end
        int space_left = length;
        int start = 0;
        string hold_input = "";
        
        // Loop through the vector of all the strings
        for (int i=0; i<input.size(); i++){
            // Calculating space remaining not including a space which comes later
            
            space_left -= input[i].length();
            
            // If this case is true then everything fits perfectly and there are no spaces so loop through and put them out to the file
            if (space_left == 0){
                
                string spaces(input[i].length(), ' ');
                
                if (hold_input == "our"){
                    cout << "1: space_left: " << space_left << " spaces: " << spaces.length();
                }

                out_file << spaces << hold_input << " ";
                
                for (int j=start; j<i; j++){
                    out_file << input[j] << " ";
                }
                
                out_file << "|\n| ";
                space_left = length - input[i].length();
                start = i+1;
                hold_input = input[i];
            }
            else if(space_left < 0){
                
                string spaces(input[i].length() + space_left, ' ');
                
                out_file << spaces << hold_input << " ";
                hold_input = input[i];
                for (int j=start; j<i; j++){
                    out_file << input[j] << " ";
                }
                
                start = i+1;
                out_file << "|\n| ";
                space_left = length - hold_input.length();
            }
            else{
                space_left -=1;
            }
            
            if (i == input.size() - 1){
                string spaces(space_left,' ');
                out_file << spaces << hold_input << " ";
                for (int j=start; j<=i; j++){
                    out_file << input[j] << " ";
                }
                out_file << "|\n";
            }
        }
    }
    else if (!(strcmp(argv[4],"full_justify"))){
        int space_left = length;
        int start = 0;
        int words = 0;
        int space1 = 0;
        int num_space1 = 0;
        int slots = 0;
        string spaces2 = "";
        
        for (int i=0; i<input.size(); i++){
            
            space_left -= input[i].length();
            
            words += 1;
            slots = words - 1;
            
            cout << "say waa: " << space_left << " input_length: " << input[i].length() << endl;
//            
//            if ((int)(space_left - slots) == (int)input[i+1].length()){
//                
//                cout <<"hey1 " << endl;
//                
//                for (int j=start; j<i; j++){
//                    out_file << input[j] << ' ';
//                }
//                
//                out_file << input[i] << " |\n| ";
//                start = i+1;
//                words = 0;
//                space_left = length;
//            }
//            else if ((int)(space_left - slots) < (int)input[i+1].length()){
            if ((int)(space_left - slots) <= (int)input[i+1].length()){
                cout << "space_left: " << space_left << endl;
                
                
                cout << "words: " << words << " slots: " << slots << endl;
                
                space1 = (int)ceil((double)space_left / (double)slots);
                
                cout << "space1: " << space1 << endl;
                
                //cout << "num_spaces: " << num_spaces << endl;
                
                num_space1 = space_left % slots;
                
                cout << "num_space1: " << num_space1 << endl;
                
                string spaces1(space1,' ');
                
                if (num_space1 != 0){
                    
                    string spaces2(space1-1, ' ');
                    
                    int bound = start+num_space1;
                    
                    for (int j=start; j<bound; j++){
                        out_file << input[j] << spaces1;
                    }
                    
                    for (int j=bound; j<i; j++){
                        out_file << input[j] << spaces2;
                    }

                }
                else{
                    for (int j=start; j<i; j++){
                        out_file << input[j] << spaces1;
                    }
                }
                
                out_file << input[i] << " |\n| ";
                
                start = i+1;
                space_left = length;
                words = 0;
                slots = 0;
            }
            else{
                if (i == input.size() - 1){
                    for (int j=start; j<i; j++){
                        out_file << input[j] << ' ';
                    }
                    string spaces(space_left - input[i].length(), ' ');
                    out_file << input[i] << spaces << " |\n";

                }
            }
        }
    }
    else{
        cout << "arg 3 incorrect";
    }
    
    out_file << hyphens << endl;
    out_file.close();
    cout << endl;
    return 0;
}

