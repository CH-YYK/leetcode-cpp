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
    string evaluate(string s, vector<vector<string>>& knowledge) {
		unordered_map<string, string> dict;
		for(vector<string>& vec : knowledge)
			dict[vec[0]] = vec[1];

		string ans;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '(') {
				int j = i + 1;
				string key;
				while(j < s.size() && s[j] != ')') 
					key += s[j++];
				if(!dict.count(key)) ans += '?';
				else ans += dict[key];
				i = j;
			} else 
				ans += s[i];
		}
		return ans;
    }
};