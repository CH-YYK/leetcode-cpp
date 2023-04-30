#include <string>
using namespace std;

class TrieNode {
public:
  TrieNode* childNode[26];
  bool isVal;
  TrieNode() : isVal(false) {
    for(int i = 0; i < 26; ++i)
      childNode[i] = nullptr;
  }
};


class WordDictionary {
private:
  TrieNode* forward;
  TrieNode* backward;
public:
  /** Initialize your data structure here. */
  WordDictionary() : forward(new TrieNode()), backward(new TrieNode()) {}

  void addWord(string word) {
    TrieNode* temp = forward;
    int n = word.size();
    for(int i = 0; i < word.size(); ++i) {
      if(!temp->childNode[word[i] - 'a'])
        temp->childNode[word[i] - 'a'] = new TrieNode();
      temp = temp->childNode[word[i]-'a'];
    }
    temp->isVal = true;

    temp = backward;
    for(int i = 0; i < word.size(); ++i) {
      if(!temp->childNode[word[n-i-1]- 'a'])
        temp->childNode[word[n-i-1] - 'a'] = new TrieNode();
      temp = temp->childNode[word[n-i-1]-'a'];
    }
    temp->isVal = true;
  }

  bool search(string word) {
    TrieNode* temp = forward;
    int n = word.size();
    if(word[0] != '.') {
      for (int i = 0; i < word.size(); ++i) {
        if (word[i] == '.')
          continue;
        if (!temp)
          break;
        temp = temp->childNode[word[i] - 'a'];
      }
      if(temp) return true;
    }

    temp = backward;
    for(int i = 0; i < word.size(); ++i) {
      if(word[n-1-i] == '.') continue;
      if(!temp) break;
      temp = temp->childNode[word[n-1-i] - 'a'];
    }
    return temp;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
