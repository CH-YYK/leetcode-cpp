#include <vector>
#include <string>
#include <stack>

using namespace std;

/* Use DP to identify palindrome substrings
 *   - dp[i][j] is true if s[i:j] is palindrome
 * DFS find all possible partitions 
 */
class Solution {
public:
  vector<vector<string>> partition(string s) {
    int n = s.size();
    memo = vector<vector<int>>(n, vector<int>(n, -1));
    vector<string> col;

    helper(col, s, 0);
    return res;
  }
private:
  vector<vector<int>> memo;
  vector<vector<string>> res;

  void helper(vector<string>& col,
              string& s,
              int i) {
    if(i == s.size()) {
      res.push_back(col);
      return ;
    }
    for(int j = i; j < s.size(); ++j) {
      if(isPalindrome(s, i, j)){
        col.push_back(s.substr(i, j-i+1));
        helper(col, s, j+1);
        col.pop_back();
      }
    }
    return;
  }

  // memo[i][j] = 1, memo[i][j] = 0, memo[i][j] = -1
  bool isPalindrome(string& s, int i, int j) {
    if(memo[i][j] >= 0)
      return memo[i][j];
    if(i >= j)   // i>j -> ""
      return memo[i][j] = 1;
    return memo[i][j] = (s[i] == s[j]) ? isPalindrome(s, i+1, j-1) : 0;
  }
};
