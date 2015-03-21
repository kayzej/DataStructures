#include <iostream>
#include <cmath>

using namespace std;

bool sort_check(double *a, int size){
	double *i;
	double temp = *a;
	cout << "a[0]: " << temp << endl;
	for (i=a; i<a+size; i++){
		if (temp <= *i){
			temp = *i;
			cout << "temp: " << temp << endl;
		}
		else{
			return false;
		}
	}
	return true;
}

int main(int argc, const char * argv[]){
	cout << "start" << endl;
	const int n = 10;
	double a[n];
	double *p;
	double *q;
	for ( p=a; p<a+n; ++p ){
		*p = sqrt( p-a );
		cout << "*p: " << *p << endl;
	}
	
	cout << "middle" << endl;
	
	for (q=&a[9]; q>a-1; q-=2){
		cout << "q: " << q << "qval: " << *q << endl;
	}
	
	cout << "end" << endl;
	
	bool sorted = sort_check(&a[0], n);
	
	if (sorted){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	
	return 0;
}
