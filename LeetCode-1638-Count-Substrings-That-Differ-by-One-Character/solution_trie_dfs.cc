#include <memory>
#include <string>
#include <vector>

using namespace std;

/* Build a Trie based on all substrings in t
 * Try search every substrings, s_ij, of s in the Trie
 * Replacing every character in s_ij and search in Trie
 * O(N^3) = O(N^2) [test substrings] * O(N) [dfs] TC and O(N^2) to build a trie
 */

struct TrieNode {
  bool is_word;
  vector<TrieNode*> children;
  int cnt;
  TrieNode() : is_word(false), cnt(0), children(26, nullptr) {}
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}
  void insert(const string& t, int i, int j) {
    TrieNode* p = root.get();
    for(int k = i; k <= j; ++k) {
      char c = t[k];
      if(!p->children[c - 'a'])
        p->children[c - 'a'] = new TrieNode();
      p = p->children[c - 'a'];
      p->cnt++;
    }
    p->is_word = true;
  }
  int search(const string& s, int i, int j) {
    TrieNode* p = root.get();
    return dfs(p, s, i, j, 1);
  }
private:
  unique_ptr<TrieNode> root;

  // TC: O(26N): go through from i -> j and only branch out for just once
  int dfs(TrieNode *root, const string &s, int i, int j, int cnt) {
    if (root == nullptr)  // defensive code
      return 0;
    if (i > j) // finish searching all characters in s[i:j+1], "root" stop at s[j]
      return cnt == 0 ? root->cnt : 0; // 1 character must be changed

    int res = 0;
    if (root->children[s[i] - 'a'])
      res += dfs(root->children[s[i] - 'a'], s, i + 1, j, cnt);

    if (cnt == 1) {
      for (int nc = 0; nc < 26; ++nc) {  // try replacing s[i] to other character
        if(!root->children[nc]) continue;
        if (nc != s[i] - 'a' && cnt == 1)
          res += dfs(root->children[nc], s, i + 1, j, cnt - 1);
      }
    } 
    return res;
  }
};


class Solution {
public:
  int countSubstrings(string s, string t) {
    Trie trie;
    for(int i = 0; i < t.size(); ++i)
      trie.insert(t, i, t.size() - 1);
    int res = 0;
    for(int i = 0; i < s.size(); ++i) {
      for(int j = i; j < s.size(); ++j) {
        res += trie.search(s, i, j);
      }
    }
    return res;
  }
};
