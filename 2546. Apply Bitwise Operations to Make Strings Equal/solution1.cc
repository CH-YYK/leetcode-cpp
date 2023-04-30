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
    bool makeStringsEqual(string s, string target) {
		// 1 0: 1 | 0 = 1, 1 ^ 0 = 1
		// 0 0: 0 | 0 = 0, 0 ^ 0 = 0
		// 0 1: 0 | 1 = 1, 0 ^ 1 = 1
		// 1 1: 1 | 1 = 1, 1 ^ 1 = 0
		// random 1 0 -> 1 1, 0 1 -> 1 1, 1 1 -> 1 0, 0 0 -> 0 0
		// i,j is randomly chosen
		// so if we have a '1' in s, we can make 0 to 1 and 1 to 0
		// 1. if s is all '0' we can change nothing
		// 2. if target is all '0' we can not achieve 
		bool haveOne = false;
		for(char c : target)
			haveOne |= c == '1';
		if(!haveOne) return s == target;
		haveOne = false;
		for(char c : s)
			haveOne |= c == '1';
		return haveOne;
    }
};