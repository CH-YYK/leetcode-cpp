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
    int widthOfBinaryTree(TreeNode* root) {
    	// BFS
    	// save the index
    	//   i -> (2*i, 2*i+1)
    	// To mitigate overflow because of he high-skewed tree
    	// 	 offset each index by its level min 
		queue<pair<long, TreeNode*>> q;
		q.emplace(0, root);
		long ans = 0;
		while(!q.empty()) {
			int size = q.size();
			long min_ = q.front().first;
			long max_ = 0;

			while(size--) {
				auto [idx, curr] = q.front();
                idx -= min_;
				max_ = max(max_, idx);
				q.pop();
				if(curr->left)
					q.emplace(idx * 2, curr->left);
				if(curr->right)
					q.emplace(idx * 2 + 1, curr->right);
			}
			ans = max(ans, max_ + 1);
		}
		return ans;
    }
};