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
    string getPermutation(int n, int k) {
        // next permutation of k steps
    	factors = vector<int>(n + 1, 1);
    	// precompute factorials
    	for(int i = 1; i <= n; ++i)
    		factors[i] = factors[i-1] * i;
    	return findPermutation(n, k, 0);
    }
private:
	vector<int> factors;
	string findPermutation(int n, int k, int state) {
		int m = n - __builtin_popcount(state);
        if(m == 0) return "";
		int i = 1;
		// find largest i, to make k <= (m-1)!
		// then i is the closest leading number
		while(i <= n) {
			if(state & (1 << i))
				i++;
			else if(k > factors[m-1]){
				k -= factors[m-1];
				i++;
			} else break;
		}
        string res;
        res += '0' + i;
		return res + findPermutation(n, k, state | (1 << i));
	}
};