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
    int maximumValue(vector<string>& strs) {
  		int ans = 0;
  		for(string& str : strs) {
  			bool word = false;
  			int num = 0;
  			for(char c : str) {
  				if(isdigit(c)) {
  					num = num * 10 + c - '0';
  				} else {
  					word = true;
  					break;
  				}
  			}
  			if(word) 
  				ans = max(ans, (int)str.size());
  			else 
  				ans = max(ans, num);
  		}
  		return ans;
    }
};