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


class Solution {
public:
    int countAnagrams(string s) {
        // A33/A22 * A33 = 3 * 6 = 18
    	// modulo multiplicative inverse
    	int n = s.size();
    	int mod = 1e9 + 7;
    	vector<long> fact(n + 1, 1), invfact(n + 1, 1);
    	for(int i = 1; i <= n; ++i) {
    		fact[i] = i * fact[i-1] % mod;
    		if(i >= 2)
	    		invfact[i] = binpow(fact[i], mod-2, mod);
    	}
    	long ans = 1;
    	string word;
    	stringstream ss(s);
    	while(ss >> word) {
    		vector<int> freq(26, 0);
    		for(char c : word)
    			freq[c - 'a']++;
    		long res = fact[word.size()];
    		for(int cnt : freq)
    			if(cnt > 1)
    				res = res * invfact[cnt] % mod;
    		ans = ans * res % mod;
    	}
        return ans;
    }  
private:
	long binpow(long a, long n, long m) {
		long res = 1;
		while(n > 0) {
			if(n % 2)
				res = res * a % m;
			a = a * a % m;
			n /= 2;
		}
		return res;
	}
};