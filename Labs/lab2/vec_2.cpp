#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
vector<double> a(1000, 0);

for (int i=0; i<1000; ++i){
    a[i]=sqrt(i);
}
    
cout << "index 0: " << a[0] << "\n";
cout << "index 2: " << a[2] << "\n";
cout << "index 16: " << a[16] << "\n";

return 0;
}