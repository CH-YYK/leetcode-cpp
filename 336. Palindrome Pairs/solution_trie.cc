#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

/* Find all palindrome prefix/suffix put the reversed rest in hashmap
 * TC: O(k^2*n), SC: O(k*n) : n words of size k averagly
 */

struct TrieNode {
  vector<TrieNode*> children;
  int index;
  TrieNode() : index(-1), children(26, nullptr) {}
  ~TrieNode() {  // destructer will take extra time
    for(TrieNode* child : children)
      if(child) delete child;
  }
};

class Trie {
public:
  Trie() : root(new TrieNode()){}
  void insert(const string& w, int index) {
    TrieNode* p = root.get();
    for(char c : w) {
      if(!p->children[c - 'a'])
        p->children[c-'a'] = new TrieNode();
      p = p->children[c - 'a'];
    }
    p->index = index;
  }

  int search(const string& w) {
    const TrieNode* p = root.get();
    for(char c : w) {
      p = p->children[c-'a'];
      if(p == nullptr) return -1;
    }
    return p->index;
  }

  int rev_search(const string& w, int i, int j) {
    const TrieNode* p = root.get();
    for(int k = j; k >= i; --k) {
      char c = w[k];
      p = p->children[c - 'a'];
      if(p == nullptr) return -1;
    }
    return p->index;
  }
private:
  unique_ptr<TrieNode> root;
};

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    int n = words.size();
    Trie trie;

    for(int i = 0; i < n; ++i)
      trie.insert(words[i], i);

    vector<vector<int>> ret;
    for(int i = 0; i < n; ++i) {
      int m = words[i].size();
      for(int j = 0; j <= m; ++j) {
        if(isPalindrome(words[i], j, m-1)) { // palindrome suffix
          int right_id = trie.rev_search(words[i], 0, j-1);
          if(right_id != -1 && right_id != i)
            ret.push_back({i, right_id});
        }
        if(j > 0 && isPalindrome(words[i], 0, j-1)) { // palindrome prefix
          int left_id = trie.rev_search(words[i], j, m-1);
          if(left_id != -1 && left_id != i)
            ret.push_back({left_id, i});
        }
      }
    }
    return ret;
  }
private:
  bool isPalindrome(const string& s, int i, int j) {
    while(i < j){
      if(s[i++] != s[j--]) return false;
    }
    return true;
  }
};
 
 
