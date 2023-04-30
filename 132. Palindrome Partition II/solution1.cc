#include <string>

using namespace std;

/* DFS i->j j->k and track cuts until i=n when s[i:j] is palindrome
 * Use memo to boost palindrome identification
 * - complexity O(n^2)
 *
 * dfs : minimum steps taken after s[i]
 * isPalindrome: whether the s[i, j] is palindrome
 */
class Solution {
public:
  int minCut(string s) {
    int n = s.size();
    memo = vector<vector<int>>(n, vector<int>(n, -1));
    memo_cuts = vector<int>(n, 0);
    int res = dfs(s, 0); // start from step-0
    return res - 1;
  }
private:
  vector<vector<int>> memo; // memo[i][j] -> whether s[i:j] is palindrome
  vector<int> memo_cuts; // memo_cuts[i] -> minimum cuts for s[i:]

  int dfs(string& s, int i) {
    if (i == s.size()) {
      return 0;
    }

    if(memo_cuts[i]) return memo_cuts[i];

    for(int j = i; j < s.size(); ++j) {
      int _min = INT_MAX;
      if(isPalindrome(s, i, j))
        _min = min(dfs(s, j + 1), _min);
    }
    return memo_cuts[i] = _min + 1;
  }

  // memo[i][j], -1 non tested, 0 not palindrome, 1 palindrome
  bool isPalindrome(string& s, int i, int j) {
    if(memo[i][j] >= 0) return memo[i][j];
    if(i >= j) return memo[i][j] = 1;
    return memo[i][j] = (s[i] == s[j]) ? isPalindrome(s, i+1, j-1) : 0;
  }
};
