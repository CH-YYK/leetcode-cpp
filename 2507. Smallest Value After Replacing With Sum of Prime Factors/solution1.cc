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

class Solution {
public:
    int smallestValue(int n) {
    	vector<int> isPrime = primesUnderN(n);    	
		vector<int> primes;
		for(int p = 2; p <= n; ++p)
			if(isPrime[p])
				primes.push_back(p);			
        while(n != 1) {
            int lastn = n;
        	int sum = 0;
        	while(n != 1) {
        		for(int p : primes) {
        			if(n % p == 0) {
        				sum += p;
        				n /= p;
        				break;
        			}
        			if(p > n)
        				break;
        		}
        	}
        	n = sum;
        	if(isPrime[sum] || lastn == sum)
        		return sum;
        }
        return n;
    }
private:
	vector<int> primesUnderN(int n) {
		vector<int> primes(n + 1, 1);
		primes[1] = 0;
		for(int p = 2; p * p <= n; p++) {
			if(primes[p])
				for(int i = p * p; i <= n; i += p)
					primes[i] = 0;
		}
		return primes;
	}
};