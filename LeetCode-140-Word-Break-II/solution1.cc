#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* Bottom-up solution
 *
 */
class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    vector<string> list;
    memo = vector<vector<vector<string>>>(s.size());
    auto ret = dfs(s, 0, wordDict);
    for(auto vec : ret) {
      reverse(vec.begin(), vec.end());
      res.push_back(build_string(vec));
    }
    return res;
  }
private:
  vector<string> res;
  vector<vector<vector<string>>> memo;

  vector<vector<string>> dfs(string& s, int i, vector<string>& wordDict) {
    if(i == s.size()) {
      return {{""}};
    }
      if(!memo[i].empty()) return memo[i];
    vector<vector<string>> ret;
    for(int j = i; j < s.size(); ++j) {
      string curr = s.substr(i, j-i+1);
      for(string key : wordDict) {
        if(curr == key) {
            auto nexts = dfs(s, j+1, wordDict);
          for(vector<string>& vec: nexts) {
            ret.push_back(vec);
            ret.back().push_back(curr);
          }
        }
      }
    }
    memo[i] = ret;
    return ret;
  }

  string build_string(vector<string>& list) {
    if(list.empty()) return "";
    string res;
    for(string& str : list) {
        if(!str.empty()) res += str + ' ';
    }
    res.pop_back();
    return res;
  }
};

