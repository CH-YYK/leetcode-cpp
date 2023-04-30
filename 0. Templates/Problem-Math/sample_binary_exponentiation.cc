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

/*
* for a^n;
* 
* if n == 0, a^n = 1
* if n is even, a ^ n = [a^(n/2)]^2
* if n is odd, a ^ n = a * {a ^ [(n-1)/2]} ^ 2
*/

class Solution {
public:
	// recursive
	long long binpow(long long a, long long n) {
		if(n == 0)
			return 1;
		long long res = binpow(a, n / 2);
		if(n % 2) // odd
			return res * res * a;
		// even
		return res * res;		
	}

	// iterative
	long long binpow_iter(long long a, long long n) {
		long long res = 1;
		while(n > 0) {
			if(n % 2) 
				res = res * a;
			a = a * a;
			b /= 2; // b >>= 1
		}
		return res;
	}
};
