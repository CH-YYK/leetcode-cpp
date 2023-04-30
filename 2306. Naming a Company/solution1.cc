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
    long long distinctNames(vector<string>& ideas) {
		// two groups 
		// group by suffix and group by leading letter
		// 
		// words are unique: 
		// 	 a leading character have unique set of suffices
		// 
		// 1. enumerate every pair of suffices and see how many combinations they can form
		//		* two suffices should not have common leading letter 
		// 		* O(N^2)
		// 2. enumerate every pair of leading letters and see how many combinations they can form
		//	 	* We are not enumerating every pair but compairing the **two sets**
		// 		* O(N^2) -> O(N)
		
		vector<unordered_set<string>> s(26);
		for(string& w : ideas) {
			s[w[0] - 'a'].insert(w.substr(1));
		}
		long long ans = 0;
		for(int i = 0; i < 26; ++i) {
			for(int j = i + 1; j < 26; ++j) {
				int common = 0;
				for(const string& w : s[i]) {
					if(s[j].count(w))
						common++;
				}
				ans += (s[i].size() - common) * (s[j].size() - common) * 2;
			}
		}
		return ans;
    }
};