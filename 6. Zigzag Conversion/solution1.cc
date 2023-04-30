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
    string convert(string s, int numRows) {
		// period p = num + num - 2
		// for each row, 
		// 0: i, i + p, i + 2p, ...
		// 1: i, i + p - 1, i + p, i+2p-1...
		// 2: i, i+p-2, 
        if(numRows == 1) return s;
		string ans;
		int p = numRows + numRows - 2;
		for(int r = 0; r < numRows; ++r) {
			// +p make for inclusively considering all
			for(int i = r; i < s.size() + p; i += p) {
				if(r > 0 && r < numRows - 1 && i > r && i - 2*r < s.size()) 
					ans += s[i - 2*r];
                if(i < s.size())
				    ans += s[i];
			}
		}
		return ans;
    }
};