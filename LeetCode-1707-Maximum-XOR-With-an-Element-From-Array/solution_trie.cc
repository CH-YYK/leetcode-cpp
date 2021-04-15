#include <vector>
#include <memory>

using namespace std;

struct TrieNode {
  vector<TrieNode*> children;
  TrieNode() : children(2, nullptr) {
    for(TrieNode* child : children)
      if(child) delete child;
  }
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}
  void insert(int num) {
    TrieNode* p = root.get();
    for(int i = 30; i >= 0; --i) {
      int b = ((1 << i) & num) > 0; // ith bit is 1 else 0
      if(!p->children[b])
        p->children[b] = new TrieNode();
      p = p->children[b];
    }
  }
  const TrieNode* get_root() const {
    return root.get();
  }
private:
  unique_ptr<TrieNode> root;
};

/* TC O(N * (2^30
   ))
 *
 */
class Solution {
public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    Trie trie;
    for(int num : nums)
      trie.insert(num);
    vector<int> ans;
    const TrieNode* root = trie.get_root();
    for(auto& pair : queries) {
      dfs(root, pair[1], pair[0], 30, 0);
      ans.push_back(res == INT_MIN? -1 : res);
      res = INT_MIN;
    }
    return ans;
  }
private:
  int res = INT_MIN;
  // backtracking
  void dfs(const TrieNode* root, int maxval, int x, int i, int num) { // i take values from {30, 0}
    if(root == nullptr) return;
    if(num > maxval) return;
    if(i == -1) {
      res = max(x ^ num, res);
      return;
    }

    int b = ((1 << i) & x) == 0;
    if(root->children[b] && num + (b << i) <= maxval) {
      dfs(root->children[b], maxval, x, i-1, num + (b << i));
    } 
    if(res != INT_MIN && num + (!b << i) <= maxval)
      dfs(root->children[!b], maxval, x, i-1, num + ((!b) << i));
  }
};
