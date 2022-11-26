// Author: Huahua
#include <memory>
#include <vector>

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
  /** Initialize data structure here */
  Trie() : root(new TrieNode()) {}

  /** Inserts a word into a trie. */
  void insert(const string& word) {
    TrieNode* p = root.get();  // root is unique_ptr<>
    for(const char c : word) {
      if(!p->children[c - 'a'])
        p->children[c - 'a'] = new TrieNode();
      p = p->children[c - 'a'];
    }
    p->is_word = true;
  }

  /** Returns if the word is in the tree */
  bool search(const string& word) const {
    const TrieNode* p = find(word);
    return p && p->is_word;
  }

  /** Returns if there is any word starts with a given prefix */
  bool startsWith(const string& prefix) const {
    return find(prefix) != nullptr;
  }

private:
  std::unique_ptr<TrieNode> root;
  const TrieNode* find(const string& prefix) const {
    const TrieNode* p = root.get();  // root is unique_ptr
    for(const char c : prefix) {
      p = p->children[c - 'a'];
      if(p == nullptr) break;
    }
    return p;
  }
};
