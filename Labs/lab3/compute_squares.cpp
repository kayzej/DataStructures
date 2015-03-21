#import <iostream>
#import <cmath>

using namespace std;

void compute_squares(int a[], int b[], int n){
	int *point_a = a;
	int *point_b = b;
	
	for (int i=0; i<n; ++i){
		*(point_b + i) = pow((*(point_a + i)),2);
	}	
}

int main(int argc, const char * argv[]){
	int n=10;
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int b[n];
	compute_squares(a, b, n);
	
	for (int i=0; i<n; ++i){
		cout << b[i] << endl;
	}
	return 0;
}