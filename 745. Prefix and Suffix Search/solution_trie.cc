#include <vector>
#include <memory>
#include <string>
using namespace std;

struct TrieNode {
  int index;
  vector<TrieNode*> children;
  TrieNode() : index(-1), children(26, nullptr) {}
  ~TrieNode() {
    for(TrieNode* child : children)
      if(child) delete child;
  }
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}
  void insert(const string& w, int index) {
    TrieNode* p = root.get();
    for(char c : w) {
      if(!p->children[c - 'a'])
        p->children[c-'a'] = new TrieNode();
      p = p->children[c - 'a'];
    }
    p->index = index;
  }
  const TrieNode* find(const string& prefix) {
    const TrieNode* p = root.get();
    for(char c : prefix) {
      p = p->children[c - 'a'];
      if(p == nullptr) return nullptr;
    }
    return p;
  }
  const TrieNode* get_root() const {
    return root.get();
  }
private:
  unique_ptr<TrieNode> root;
};

class WordFilter {
public:
  WordFilter(vector<string> &words) {
    _words = words;
    int i = 0;
    for(string& w : words)
      trie.insert(w, i++);
  }

  int f(string prefix, string suffix) {
    const TrieNode* root = trie.get_root();
    dfs(root, prefix, 0, suffix, 0);
    int tmp = res;
    res = -1, maxlen = 0;
    return tmp;
  }
private:
  int res = -1, maxlen = 0;
  vector<string> _words;
  Trie trie;

  void dfs(const TrieNode* root, string& prefix, int j, string& suffix, int i) {
    if(root == nullptr) return;
    if(i == suffix.size() && j < prefix.size()) return;
    if(i == suffix.size() && j == prefix.size()) {
      if(root->index != -1 && _words[root->index].size() >= maxlen)
        maxlen = (int)_words[root->index].size(), res = root->index;
      return ;
    }

    if(j < prefix.size()) {  // search on prefix  and suffix
      if(i < suffix.size() && prefix[j] == suffix[i])
        dfs(root->children[prefix[j] - 'a'], prefix, j+1, suffix, i+1);
      dfs(root->children[prefix[j] - 'a'], prefix, j+1, suffix, i);
    } else {  // search on suffix only
      for (int k = 0; k < 26; ++k) {
        if (!root->children[k])
          continue;
        if (k == suffix[i] - 'a')
          dfs(root->children[k], prefix, j, suffix, i + 1);
        dfs(root->children[k], prefix, j, suffix, i);
      }
    }
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
