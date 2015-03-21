#include <cassert>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    
    cout << "What is your first name? ";
    string first;
    cin >> first;
    
    const string star_line(first.size()+4, '*');
    const string blanks(first.size()+2, ' ');
    const string empty_line = '*' + blanks + '*';
    string one_line = empty_line;
    
    cout << '\n' << star_line << '\n' << empty_line << endl;
    for (int i=0;i<first.size();i++){
        //assert (one_line[i+2] == 'x');
        one_line[i+2] = first[i];
        cout << one_line << '\n';
        one_line[i+2] = ' ';
    }
    
    cout << empty_line << '\n' << star_line << endl;
    
    return 0;
}