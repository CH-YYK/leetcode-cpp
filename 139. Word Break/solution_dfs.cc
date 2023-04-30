#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> word_dict;
    for(string& str : wordDict)
      word_dict.insert(str);
    memo = vector<int>(s.size(), -1);
    return dfs(s, 0, word_dict);
  }
private:
  vector<int> memo;
  bool dfs(string& s, int i, unordered_set<string>& word_dict) {
    if(i == s.size()) {
      return true;
    }
    if(memo[i] >= 0) return memo[i];
    bool canbreak = false;
    for(int j = i; j < s.size(); ++j) {
      if(!word_dict.count(s.substr(i, j-i+1))) continue;
      canbreak |= dfs(s, j+1, word_dict);
    }
    return memo[i] = canbreak;
  }
};
