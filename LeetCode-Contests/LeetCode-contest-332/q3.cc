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
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        // 32n
        int n = s.size();
        unordered_map<int, vector<int>> vals;
        for(int i = 0; i < queries.size(); ++i)
        	vals[queries[i][0] ^ queries[i][1]].push_back(i);

        vector<vector<int>> ans(queries.size(), {-1, -1});
        for(int i = 0; i < n; ++i) {
        	int num = 0;
        	int l = i;
        	for(int j = i; j < min(i + 31, n); ++j) {
        		if(num == 0 && s[j] == '0') l++;
        		num <<= 1;
        		num |= (s[j] - '0');
        		if(vals.count(num)) {
        			for(int k : vals[num])
        				ans[k] = {min(j, l), j};
                    vals.erase(num);
        		}
        	}
        }
        return ans;
    }
};