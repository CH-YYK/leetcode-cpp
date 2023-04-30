#include <string>
#include <memory>
#include <vector>

using namespace std;

/* Build a Trie based on all substrings in t
 * Try search every substrings, s_ij, of s in the Trie
 * Replacing every character in s_ij and search in Trie
 * O(N^2) TC and O(N^2) to build a trie
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
  int search(const string& s, int i, int j){
    const TrieNode* p = root.get();
    for(int k = i; k <= j; ++k) {
      char c = s[k];
      p = p->children[c - 'a'];
      if(p == nullptr) return 0;
    }
    return p->cnt;
  }
private:
  unique_ptr<TrieNode> root;
};


class Solution {
public:
  int countSubstrings(string s, string t) {
    Trie trie;
    for(int i = 0; i < t.size(); ++i)
      trie.insert(t, i, t.size() - 1);
    int res = 0;
    for(int i = 0; i < s.size(); ++i) {
      for(int j = i; j < s.size(); ++j)
        for (int k = i; k <= j; ++k) {
          char c = s[k];
          for(char nc = 'a'; nc <= 'z'; ++nc)
            if(nc == c) continue;
            else {
              s[k] = nc;
              res += trie.search(s, i, j);
            }
          s[k] = c;
        }
    }
    return res;
  }
};
