#include <memory>
#include <vector>
using namespace std;

struct TrieNode {
  bool is_word;
  vector<TrieNode*> children;
  TrieNode() : is_word(false), children(26, nullptr) {}
};

class Trie {
public:
  Trie() : root(new TrieNode()) {};
  void insert(const string& w) {
    TrieNode* p = root.get();
    for(char c : w) {
      if(!p->children[c-'a'])
        p->children[c-'a'] = new TrieNode();
      p = p->children[c-'a'];
    }
    p->is_word = true;
  }
  bool check(const string &w) {
    const TrieNode* p = root.get();
    for(char c : w) {
      if(!p->children[c-'a']) return false;
      if(!p->children[c-'a']->is_word) return false;
      p = p->children[c-'a'];
    }
    return true;
  }
private:
  unique_ptr<TrieNode> root;
};

class Solution {
public:
  string longestWord(vector<string> &words) {
    Trie trie;
    for(string& w : words) {
      trie.insert(w);
    }
    int maxlen = 0;
    string res;
    for(string& w : words) {
      if(trie.check(w) && w.length() >= maxlen)
        if(maxlen == w.length()) res = min(res, w);
        else maxlen = w.length(), res = move(w);
    }
    return res;
  }
};
