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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    	// make a string representation of a subtree
    	// repr: (left rootvalue right)
    	// 	(() 4 (()2(1)))
    	// At most, there will be 5000 nodes with val = 200, which
    	//  result in the length of string repre to 5000 * (200 + 2) -> 10^6
    	// 
    	// Optimized: if a subtree A is a duplicate of subtree B, A's children subtrees
    	// are already duplicates of B's children subtrees
    	traverse(root);
    	return ans;
    }
private:
	unordered_map<string, int> mp;
	vector<TreeNode*> ans;
	int global_id = 1;
	int traverse(TreeNode* root) {
		if(root == nullptr) return 0;
		
		string repr = 
			to_string(traverse(root->left)) + '|'
			+ to_string(root->val) + '|' 
			+ to_string(traverse(root->right));

		if(mp.count(repr) && mp[repr] > 0) {
			ans.push_back(root);
            mp[repr] *= -1;
		} else if(!mp.count(repr)) {
			mp[repr] = (global_id++);
		}
		return abs(mp[repr]);
	}
};