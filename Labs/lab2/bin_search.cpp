#include <iostream>

using namespace std;

bool binsearch(const vector<double>& v, int low, int high, double x) {
    while (notfnd) {
        if (high == low){
            return x == v[low];
        }
        if (x <= v[mid]){
        
        }
    }
}


int main(){
    
    bool notfnd = true;
    vector <double> v;
    double x;
    
    cout << "x: " << endl;
    cin >> x;
    
    return binsearch(v, 0, v.size()-1, x);
    return 0;
}