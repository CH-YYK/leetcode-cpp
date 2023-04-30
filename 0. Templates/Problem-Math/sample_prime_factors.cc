// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

vector<int> getPrimesUnderN(int N) {
	vector<int> isPrime(N + 1, 1);
	isPrime[0] = 0;
	isPrime[1] = 0;

	// exclude all even numbers except 2
	for(int i = 2 * 2; i <= N; i += 2) 
		isPrime[i] = 0;

	// exclude odd numbers with no-prime factors
	for(int i = 3; i <= N; i += 2) {
		if(isPrime[i]) {
			for(int j = i + i; j <= N; j += i)
				isPrime[j] = 0;
		}
	}

	// extract all prime numbers
	vector<int> primes;
	for(int i = 2; i <= n; ++i) 
		if(isPrime[i])
			primes.push_back(i);
	return primes;
}

vector<int> sieveOfEratosthenes(int n) {
	//  O(n*log(log(n)))
	vector<int> isPrime(n + 1, 1);
	for(int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if(isPrime[p]) {
            // Update all *multiples* of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.			
			for(int i = p * p; i <= n; i += p)
				isPrime[i] = 0;
		}
	}
	vector<int> primes;
	for(int p = 2; p <= n; ++p)
		if(isPrime[p])
			primes.push_back(p);
	return primes;
}

vector<int> getPrimeFactors(vector<int>& primes, int num) {
	int p = 0;
	vector<int> factors;
	while(num > 1 && p < primes.size() && primes[p] <= num) {
		if(num % primes[p] == 0) {
			num /= primes[p];
			factors.push_back(primes[p]);
		}
		p++;
	}
	return factors;
}

unordered_map<int,int> getPrimeFactorsCounts(int num) {
	vector<int> primes = getPrimesUnderN(num);
	int p = 0;
	unordered_map<int,int> factors;
	while(num > 1 && p < primes.size() && primes[p] <= num) {
		while(num % primes[p] == 0) {
			num /= primes[p];
			factors[primes[p]]++;
		}
		p++;
	}
	return factors;	
}