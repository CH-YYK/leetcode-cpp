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
    long long kthLargestLevelSum(TreeNode* root, int k) {
    	priority_queue<long long> pq; // maxheap
    	queue<TreeNode*> q;
    	q.push(root);

    	while(!q.empty()) {
    		int size = q.size();
    		long long sum = 0;
    		while(size--) {
    			TreeNode* curr = q.front();
    			q.pop();
    			sum += curr->val;
    			if(curr->left) q.push(curr->left);
    			if(curr->right) q.push(curr->right);
    		}
    		pq.push(sum);
    	}

    	if(pq.size() < k) return -1;
    	while(k-- > 1) {
    		pq.pop();
    	}
    	return pq.top();
    }
};