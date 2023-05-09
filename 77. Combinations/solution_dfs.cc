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
    vector<vector<int>> combine(int n, int k) {
        // find all subsequences of size k 
        // Using dfs, for each i we have
        //		either add i or do nothing
        vector<int> path;
        dfs(path, 1, k, n);
        return ans;
    }
private:
	vector<vector<int>> ans;
	void dfs(vector<int>& path, int i, int k, int n) {
		if(path.size() == k) {
			ans.push_back(path);
			return;
		}
		if(path.size() + n - i + 1 < k) 
			return;
		if(i == n + 1) return;

		dfs(path, i + 1, k, n);
		path.push_back(i);
		dfs(path, i + 1, k, n);
		path.pop_back();
	}
};