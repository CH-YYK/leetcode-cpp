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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		// winning condition
		// subtree + "above common ancestor" is larger
		// find a blue such that large subtree and shorter path to LCS (least common ancestor)
		// greedy: left child/right child/parent of the red 
		this->x = x;
        dfs(root);
		return max(max(left, right), n - left - right - 1) > n / 2;
    }
private:
	int x;
	int left, right;
	TreeNode* red = nullptr;
	int dfs(TreeNode* node) {
		if(node == nullptr) return 0;
		int l = dfs(node->left);
		int r = dfs(node->right);
		if(node->val == x)
			left = l, right = r;
		return l + r + 1;
	}
};