#import <iostream>

using namespace std;

int main() {
	cout << "Enter the size of the array: ";
	int n,j;
	int *i;
	cin >> n;
	int *a = new int[ n ];
	
	cout << "a: " << a << endl;
	
	for ( i=a; i<a+n; ++i ){
		cout << i << ": ";
		cin >> *i;
	}
	
	// for ( j=0; j<n; ++j )
	// 	cout << "j: " << a[j] << endl;
	a[n] = 19;
	a[n+1] = 25;
	a[2*n] = 100;
	
	cout << "a[n]: " << a[n] << endl;
	cout << "a[n+1]: " << a[n+1] << endl;
	cout << "a[2*n]: " << a[2*n] << endl;
	cout << endl;
	
	int *temp = new int[ 2*n ];
	
	for (int k=0; k<n; ++k){
		*(temp+k) = *(a+k);
	}
	
	//delete a;
	//delete [] a;
	
	cout << "a: " << a << endl;
	
	a = temp;
	
	for ( j=0; j<n; ++j )
		cout << temp+j <<": " << temp[j] << endl;
	
	cout << "a[n]: " << a[n] << endl;
	cout << "a[n+1]: " << a[n+1] << endl;
	cout << endl;
	
	return 0;
}