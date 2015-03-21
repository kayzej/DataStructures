#include <iostream>
#include <cmath>
#include <cstdlib>
#include <Vector>
using namespace std;

void fib(long a, long b, long max, long i, long sum){
	long c = a+b;
	if (c>=max){
		cout << "c: " << c << " max: " << max << endl;
		cout << "done" << endl;
		cout << "sum is: " << sum << endl;
		return;
	}
	else{
		if (i%3 == 0){
			sum+=c;
		}
		cout << "fib " << i << ": " << c << endl;
		return fib(b, c, max, i+1, sum);
	}
}

int main(int argc, char* argv[]) {
	
	long n;
	cout << "enter n: " << endl;
	cin >> n;
	
	fib(1, 2, n, 1, 2);
	
	return 0;
	
}