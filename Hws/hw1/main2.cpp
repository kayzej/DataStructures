#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    
    // Using the convention set by the Lectures to check that the user
    // inputted the correct number of arguments
    
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
    out_file << hyphens << "\n| ";
    
    // Storing all the strings in an vector to loop through later
    // (derp what else are vectors for derp)
    
    vector<string> input;
    string input_string;
    while (txt_file >> input_string){
        if (input_string != " "){
            input.push_back(input_string);
        }
    }
    
    int space_left = length;
    int vec_length = input.size();
    int start = 0;
    int num_spaces;
    string spaces = "";
    string hold_input = "";
    
    for (int i=0; i<vec_length; i++){
        space_left -= input[i].length();
        
        if (space_left == 0){
            if (!(strcmp(argv[4], "flush_left"))){
                for (int j=start; j<i; j++){
                    out_file << input[j] << ' ';
                }
                out_file << input[i] << " 1|\n| ";
            }
            else if (!(strcmp(argv[4], "flush_right"))){
                out_file << hold_input << ' ';
                for (int j=start; j<i; j++){
                    out_file << input[j] << ' ';
                }
                out_file << input[i] << " 2|\n| ";
            }
            else{
                continue;
            }
        
            start = i+1;
            spaces = "";
            space_left = length;
            hold_input = "";
        }
        
        else if (space_left < 0){
            num_spaces = input[i].length() + space_left;
            string spaces(num_spaces, ' ');
            
            if (!(strcmp(argv[4], "flush_left"))){
                
                for (int j=start; j<i; j++){
                    out_file << input[j] << ' ';
                }
                out_file << spaces << " 3|\n| ";
                
                out_file << input[i] << ' ';
                
                if (i == vec_length - 1){
                    string spaces(length - input[i].length(), ' ');
                    out_file << spaces << " 4|\n";
                }
            }
            
            else if (!(strcmp(argv[4], "flush_right"))){
                
                out_file << spaces << ' ' << hold_input << ' ';
                
                for (int j=start; j<i; j++){
                    out_file << input[j] << ' ';
                }
                
                out_file << " 5|\n| ";
                hold_input = input[i];
            }
            
            else if (!(strcmp(argv[4], "full_justify"))){
                continue;
            }
            
            else{
                cerr << "wtf mate\n";
            }
            space_left = length - input[i].length() - 1;
            start = i+1;
            spaces = "";
        }
        
        else{
            if (i==vec_length -1){
                
                num_spaces = space_left;
                string spaces(num_spaces, ' ');
                
                if (!(strcmp(argv[4], "flush_left"))){
                    cout << "say walalala" << endl;
                    for (int j=start; j<i; j++){
                        out_file << input[j] << ' ';
                    }
                    out_file << input[i] << spaces << " 6|\n";
                }
                else if (!(strcmp(argv[4], "flush_right"))){
                    cout << "shiiiit" << endl;
                    out_file << spaces << hold_input;
                    for (int j=start; j<i; j++){
                        out_file << ' ' << input[j];
                    }
                    out_file << ' ' << input[i] << " 7|\n";
                }
                else{
                    cout << "say whaaaa" << endl;
                }
            }
            space_left -= 1;
        }
    }
    
    out_file << hyphens << endl;
    out_file.close();
    cout << endl;
    return 0;
}

