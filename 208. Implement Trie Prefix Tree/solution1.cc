
#include <string>
using namespace std;

class TrieNode {
public:
  TrieNode* childNode[26];
  bool isVal;  // is this the end node of the tree
  TrieNode() : isVal(false) {
    for(int i = 0; i < 26; ++i)
      childNode[i] = nullptr;
  }
};


class Trie {
  TrieNode* root;
public:
  /** Initialize your data structure here. */
  Trie() : root(new TrieNode()) {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode* temp = root;
    for(int i = 0; i < word.size(); ++i) {
      if(!temp->childNode[word[i] - 'a'])
        temp->childNode[word[i] - 'a'] = new TrieNode();
      temp = temp->childNode[word[i]-'a'];
    }
    temp->isVal = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode* temp = root;
    for(int i = 0; i < word.size(); ++i) {
      if(!temp) break;
      temp = temp->childNode[word[i] - 'a'];
    }
    return temp ? temp->isVal: false;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    TrieNode* temp = root;
    for(int i = 0; i < prefix.size(); ++i){
      if(!temp) break;
      temp = temp->childNode[prefix[i] - 'a'];
    }
    return temp;  // if null: not all char in the prefix tree, if !null: all characters were in the tree.
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
