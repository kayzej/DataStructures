#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "What is your first name? ";
    string first;
    //string spaces;
    cin >> first;
    cout << endl;
    
    int asts = first.size() + 4;
    string ast_full(asts, '*');
    string spaces1(asts-2, ' ');
    cout << ast_full << endl << '*' << spaces1 << '*' << endl;
    
    for (int i=0; i<first.size();i++){
        string spacesB(i+1, ' ');
        string spacesA(first.size() - i, ' ');
        cout << '*' << spacesB << first.substr(i,1) << spacesA << '*' << endl;
    }
    
    cout << '*' << spaces1 << '*' << endl << ast_full << endl;
    
    return 0;
}