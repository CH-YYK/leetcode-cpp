// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Trie {
  Trie *ch[26] = {};
  int cnt = 0;
  void insert(string &w) {
    auto n = this;
    for (char c : w) {
      if (n->ch[c - 'a'] == nullptr)
        n->ch[c - 'a'] = new Trie();
      n = n->ch[c - 'a'];
      ++n->cnt;
    }
  }

  int count(string &w, int i = 0) {
    return cnt + (i == w.size() ? 0 : ch[w[i] - 'a']->count(w, i + 1));
  }
};

class Solution {
public:
  vector<int> sumPrefixScores(vector<string> &words) {
    // trie tree prefix match
    Trie t;
    for (string &w : words) {
      t.insert(w);
    }
    vector<int> res;
    for (auto &w : words)
      res.push_back(t.count(w));
    return res;
  }
};

int main() {}
