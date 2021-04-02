#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<string> partition;
    int n = s.length();
    memo = vector<vector<int>>(n, vector<int>(n, -1));
    backtrack(s, 0, partition);
    return res;
  }
private:
  vector<vector<string>> res;
  vector<vector<int>> memo;
  void backtrack(string& s, int i, vector<string>& partition) {
    if(i == s.size()) {
      res.push_back(partition);
      return;
    }
    for(int j = i; j < s.size(); ++j) {
      if(!isPalindrome(s, i, j)) continue;
      partition.push_back(s.substr(i, j-i+1));
      backtrack(s, j+1, partition);
      partition.pop_back();
    }
  }
  bool isPalindrome(string& s, int i, int j) {
    if(i >= j) return true;
    if(memo[i][j] >= 0) return memo[i][j];
    if(s[i] == s[j])
      return memo[i][j] = isPalindrome(s, i+1, j-1);
    return memo[i][j] = false;
  }
};
