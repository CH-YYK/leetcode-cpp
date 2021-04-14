#include <memory>
#include <pair>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/* minheap of size k (as we want to keep top K most frequent elements) to take top K frequent in O(K)
 * Trie tree to boost comparison between words,
 *    e.g. if we have two "sunn"s in the list, we don't need to restart searching to get other 3 "sunny" in the list
 */

struct TrieNode {
  bool is_word;
  vector<TrieNode*> children;
  int cnt;
  TrieNode() : is_word(false), children(26, nullptr), cnt(0) {}
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}

  void insert_and_add(const string& w) const {
    TrieNode* p = root.get();
    for(char c : w) {
      if(!p->children[c-'a'])
        p->children[c-'a'] = new TrieNode();
      p = p->children[c - 'a'];
    }
    p->is_word = true;
    p->cnt++;
  }
  
  const TrieNode* get_root() const {
    return root.get();
  }
private:
  unique_ptr<TrieNode> root;
};


// if cmp(lhs, rhs) -> true, lhs will be placed botton in the heap, i.e, rhs will be pushed top
//  default pq use less<int> whish is thus minheap by default
struct cmp_pair {
  bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) {
    if(lhs.first > rhs.first) return true;
    else if(lhs.first == rhs.first) return lhs.second < rhs.second;
    return false;
  }
};

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    this->k = k;
    Trie trie;
    for(string& w : words)
      trie.insert_and_add(w);

    const TrieNode* root = trie.get_root();
    string curr;
    dfs(root, curr);

    vector<string> res;
    while (!q.empty()) {
      res.push_back(q.top().second);
      q.pop();
    }
    reverse(begin(res), end(res));
    return res;
  }
private:
  int k;
  priority_queue<pair<int, string>, vector<pair<int, string>>, cmp_pair> q; // minHeap
  void dfs(const TrieNode* root, string& curr) {
    if(root == nullptr) return;

    if(root->is_word)
      if(q.size() < k)
        q.push({root->cnt, curr});
      else if(root->cnt > q.top().first){
        q.pop();
        q.push({root->cnt, curr});
      }

    for(int j = 0; j < 26; ++j) {
      if (root->children[j]) {
        curr.push_back('a' + j);
        dfs(root->children[j], curr);
        curr.pop_back();
      }
    }
  }
};
