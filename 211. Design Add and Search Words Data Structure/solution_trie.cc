#include <vector>
#include <string>
#include <memory>
using namespace std;

struct TrieNode {
  bool is_word;
  vector<TrieNode*> children;
  TrieNode() : is_word(false), children(26, nullptr) {}
  ~TrieNode() {
    for(TrieNode* child : children)
      if(child) delete child;
  }
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}
  void insert(const string& w) {
    TrieNode* p = root.get();
    for(char c : w) {
      if(!p->children[c - 'a'])
        p->children[c-'a'] = new TrieNode();
      p = p->children[c-'a'];
    }
    p->is_word = true;
  }
  TrieNode* find(const string& prefix) {
    TrieNode* p = root.get();
    for(char c : prefix) {
      p = p->children[c - 'a'];
      if(p == nullptr) return nullptr;
    }
    return p;
  }
private:
  unique_ptr<TrieNode> root;
};

class WordDictionary {
public:
  /** Initialize your data structure here. */
  WordDictionary() {
    trie = Trie();
  }

  void addWord(string word) {
    trie.insert(word);
  }

  bool search(string word) {
    int i = 0;
    while(i < word.size() && word[i] != '.') i++;
    string prefix = word.substr(0, i);
    TrieNode* p = trie.find(prefix);
    return dfs(p, word, i);
  }

private:
  Trie trie;
  bool dfs(TrieNode* root, string& suffix, int i) {
    if(root == nullptr) return false;
    if(i == suffix.size()) return root->is_word;

    bool res = false;

    if(suffix[i] == '.') {
      for(int k= 0; k < 26; ++k)
        res |= dfs(root->children[k], suffix, i+1);
    } else if(root->children[suffix[i] - 'a'])
      res |= dfs(root->children[suffix[i] - 'a'], suffix, i+1);
    return res;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
