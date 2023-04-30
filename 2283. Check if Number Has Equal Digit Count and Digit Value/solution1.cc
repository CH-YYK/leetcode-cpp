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
    bool digitCount(string num) {
		vector<int> freq(10, 0);
		for(char c : num)
			freq[c - '0']++;
		for(int i = 0; i < num.size(); ++i)
			if(freq[i] != num[i] - '0') return false;
		return true;
    }
};