#include <memory>
#include <string>
#include <vector>
using namespace std;

/* Modify each word to "suffix_word" after extracting the suffix
 * Put the "suffix_word" in Trie and mark each node with the index
 *
 * when doing query using "f", create "suffix_prefix" and search it in trie
 * return the index if trienode not null
 */
struct TrieNode {
  int index;
  vector<TrieNode*> children;
  TrieNode() : index(-1), children(27, nullptr) {} // with '{' at the end
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
      p->index = index;
    }
  }
  int search(const string& w) {
    const TrieNode* p = root.get();
    for(char c : w) {
      p = p->children[c - 'a'];
      if(p == nullptr) break;
    }
    return p->index;
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
    trie = Trie();
    for(int i= 0; i < words.size(); ++i) {
      int m = words[i].size();
      for(int j = 0; j < words[i].size(); ++j) {
        // build search key "suffix{word" and insert to trie
        string tmp = words[i].substr(j, m - j);
        tmp += '{';
        tmp += words[i];
        trie.insert(tmp, i);
      }
    }
  }

  int f(string prefix, string suffix) {
    string key = suffix;
    // build search key and search in trie
    key += '{';
    key += prefix;
    int i = trie.search(key);
    return i;
  }
  private:
  Trie trie;
};




/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
