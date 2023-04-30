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

class Solution2 {
public:
    int countAnagrams(string s) {
        // A33/A22 * A33 = 3 * 6 = 18
        int mod = 1e9 + 7;
        long ans = 1;
        vector<long> factorials(s.size() + 1, -1);
        function<long(long)> factorial = [&](long n) {
            if(n == 0) return 1l;
            if(factorials[n] > -1) return factorials[n];
        	return factorials[n] = n * factorial(n-1) % mod;
        };
        stringstream ss(s);
        string word;
        while(ss >> word) {
        	unordered_map<int,int> mp;
        	for(char c : word) {
        		mp[c]++;
        	}
        	long base = factorial(mp.size());
        	for(auto& [k, cnt] : mp) {
        		base /= factorial(cnt);
        	}
        	ans = ans * base % mod;
        }
        return ans;
    }  
};
