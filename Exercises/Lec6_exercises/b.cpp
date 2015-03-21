// Using Sieve of Eratostenes determine all prime numbers less than or
// equal to an integer provided on the command line.
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[]) {
	// Check usage. Take n from the 1st argument. Make sure it is positive.
	if (argc != 2) {
		cerr << "Usage:\n " << argv[0] << " n\n" << "where n is a positive integer\n";
		return 0;
	}
	int n = atoi(argv[1]);
	if (n <= 0) {
		cerr << "Usage:\n " << argv[0] << " n\n" << "where n is a positive integer\n";
		return 0;
	}
	
	int prime_count = 0;
	
	// Create and initialize a dynamically allocated array to keep track
	// of whether the number 1->n are prime
	int* primes = new int[];
	primes[0] = 1;
	primes[1] = 2;
	
	// Process and output the numbers that are prime
	
	for (int i=3; i<n; i++){
		int j=0;
		bool prime = true;
		while(j<primes.length)
			if (i%primes[j] !=0)
		}
	}
	
	// Release the dynamically allocated memory
	
	
	
	cout << "\nThere are " << prime_count << " primes <= " << n << endl;
	return 0;
}
