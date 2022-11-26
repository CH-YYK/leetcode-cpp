#include <memory>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
  bool is_word;
  unordered_map<char, TrieNode*> children;
  TrieNode() : is_word(false) {}
  ~TrieNode() {
    for(auto& kv : children)
      if(kv.second) delete kv.second;
  }
};

class Trie {
public:
  /** Initialize data structure here */
  Trie() : root(new TrieNode()) {}

  /** Inserts a word into a trie. */
  void insert(const string &word) {
    TrieNode *p = root.get(); // root is unique_ptr<>
    for (const char c : word) {
      if (!p->children.count(c))
        p->children[c] = new TrieNode();
      p = p->children[c];
    }
    p->is_word = true;
  }

  /** Returns if the word is in the tree */
  bool search(const string &word) const {
    const TrieNode *p = find(word);
    return p && p->is_word;
  }

  /** Returns if there is any word starts with a given prefix */
  bool startsWith(const string &prefix) const {
    return find(prefix) != nullptr;
  }

private:
  unique_ptr<TrieNode> root;

  const TrieNode* find(const string& prefix) const {
    const TrieNode* p = root.get();
    for(const char c : prefix) {
      if(p->children.count(c))
        p = p->children.at(c); // "const" method to access key c
      else return nullptr;
    }
    return p;
  }
};
