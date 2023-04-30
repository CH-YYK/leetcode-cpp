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
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
		// when LCP is not valid?
		// 
		// Basically the intuition is A[i] == A[j] when lcp[i][j] > 0
		// 		and A[i] != A[j] when lcp[i][j] = 0. 
		// 
		// O(N^3) greedy method:
		// 	lcp[i][j] = 0 -> A[i] != A[j]
		// 	lcp[i][j] = k -> A[i: i+ k] = A[j: j+k]
		// 	generating and updating -> O(N^3)
    	// 
    	// However we can initialize the string following the basic rule and validating later
    	// if A[i] == A[j] -> lcp[i][j] = lcp[i+1][j+1] + 1;
    	// if A[i] != A[j] -> lcp[i][j] = 0;
		// 	
		int n = lcp.size(), c = 0;
		vector<int> A(n, 0);
		for(int i = 0; i < n; ++i) {
			if(A[i]) continue;
			if(++c > 26) return "";
			for(int j = i; j < n; ++j)
				if(lcp[i][j] > 0)
					A[j] = c;
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				int v = i + 1 < n && j + 1 < n ? lcp[i+1][j+1] : 0;
				if(A[i] == A[j]) {
					if(lcp[i][j] != v + 1)
						return "";
                } else if(lcp[i][j] != 0)
                    return "";
			}
		}

		string ans;
		for(int i = 0; i < n; ++i) {
			ans += 'a' + A[i] - 1;
		}
		return ans;
    }
};