#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    memo = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
    int res = 0;
    for(int i = 0; i < s.size(); ++i)
      for(int j = i; j < s.size(); ++j)
        if(ispalindrom(s, i, j)) res++;
    return res;
  }
private:
  vector<vector<int>> memo;
  bool ispalindrom(string& s, int i, int j) {
    if(i > j) return true; // empty string is palidrome
    if(i == j) return memo[i][j] = true;
    if(memo[i][j] >= 0) return memo[i][j];
    if(s[i] == s[j]) return memo[i][j] = ispalindrom(s, i+1, j-1);
    return memo[i][j] = false;
  }
};
