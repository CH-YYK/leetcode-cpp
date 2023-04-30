#include <string>
using namespace std;

struct TrieNode {
  TrieNode* next[26];
  bool isword = false;
  TrieNode() {
    for(int i = 0; i < 26; ++i)
      next[i] = nullptr;
  }
};


class Trie {
private:
  TrieNode* node;
public:
  /** Initialize your data structure here. */
  Trie() {
    node = new TrieNode();
  }
  ~Trie() {
    delete node;
  }
  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode* tmp = node;
    for(char c : word) {
      if(!tmp->next[c-'a'])  // if next node exists
        tmp->next[c-'a'] = new TrieNode();
      tmp = tmp->next[c - 'a'];
    }
    tmp->isword = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode* tmp = node;
    for(char c : word) {
      if(tmp->next[c - 'a']) // can find c in children (next)
        tmp = tmp->next[c - 'a'];
      else return false;
    }
    return tmp->isword;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    TrieNode* tmp = node;
    for(char c : prefix) {
      if(tmp->next[c - 'a'])   // can find c in children (next)
        tmp = tmp->next[c - 'a'];
      else return false;
    }
    return true;
  }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
