#include <vector>
#include <memory>
using namespace std;

struct TrieNode {
  bool is_word;
  vector<TrieNode*> children;
  TrieNode() : is_word(false), children(26, nullptr){}
  ~TrieNode(){
    for(int i = 0; i < 26; ++i)
      if(children[i]) delete children[i];
  }
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}
  void insert(string& w) {
    TrieNode* p = root.get();
    for(char c : w) {
      if(!p->children[c - 'a'])
        p->children[c-'a'] = new TrieNode();
      p = p->children[c- 'a'];
    }
    p->is_word = true;
  }

  bool search(const string& w) {
    const TrieNode* p = find(w);
    return p && p->is_word;
  }

  bool startsWith(const string& prefix) {
    const TrieNode* p = find(prefix);
    return p == nullptr;
  }
private:
  unique_ptr<TrieNode> root;
  const TrieNode* find(const string& prefix) {
    const TrieNode* p = root.get();
    for(char c : prefix) {
      p = p->children[c - 'a'];
      if(p == nullptr) break;
    }
    return p;
  }
};

class Solution {
public:
  vector<vector<int>> indexPairs(string text, vector<string> &words) {
    Trie trie;
    for(string& w : words)
      trie.insert(w);

    vector<vector<int>> res;
    for(int i = 0; i < text.size(); ++i) {
      for(int j = i; j < text.size(); ++j){
        if(trie.search(text.substr(i, j - i + 1)))
          res.push_back({i, j});
      }
    }
    return res;
  }
};
