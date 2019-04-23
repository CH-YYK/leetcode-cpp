#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    /*
     * Recursion without memoization.
     *      if s[i] == p[j] or p[j] == '.' --> isMatch(i, j) = isMatch(i-1, j-1)
     *      if s[i] != p[j] and p[j] != '*':
     *              --> isMatch(i, j) = False
     *      if p[j] == '*':
     *              --> isMatch(i, j) = isMatch(i, j-1) # single precedding character
     *              --> isMatch(i, j) = isMatch(i, j-2) # zero preceeding character
     *              --> isMatch(i, j) = isMatch(i-1, j) and (s[i] == p[j-1] || p[j-1] == '.') ## multiple preceeding characters
     */
    
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        return isMatch(s, p, m-1, n-1);
    }
private:
    bool isMatch(string s, string p, int i, int j) {
        if(i < 0 && j < 0) return true;
        if(j < 0) return false;
        
        if(i >= 0 && (s[i] == p[j] || p[j] == '.'))
            return isMatch(s, p, i-1, j-1);

        if(p[j] == '*') {
            bool c0 = isMatch(s, p, i, j-2);
            bool c1 = i >= 0 ? isMatch(s, p, i, j-1) : false;
            bool c2 = i >= 1 ? isMatch(s, p, i-1, j) && (s[i] == s[i-1] || p[j-1] == '.') : false;
            return c1 || c0 || c2;
        }
        return false;
    }
};

class Solution2 {
    /*
     * Recursion with memoization.
     *      if s[i] == p[j] or p[j] == '.' --> isMatch(i, j) = isMatch(i-1, j-1)
     *      if s[i] != p[j] and p[j] != '*':
     *              --> isMatch(i, j) = False
     *      if p[j] == '*':
     *              --> isMatch(i, j) = isMatch(i, j-1) # single precedding character
     *              --> isMatch(i, j) = isMatch(i, j-2) # zero preceeding character
     *              --> isMatch(i, j) = isMatch(i-1, j) and (s[i] == p[j-1] || p[j-1] == '.') ## multiple preceeding characters
     * 
     * add Memoization
     *      duplicates: isMatch(i, j)
     */
    
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        memo = vector<vector<int>> (m+1, vector<int>(n+1, -1));
        return isMatch(s, p, m-1, n-1);
    }
private:
    vector<vector<int>> memo;
    bool isMatch(string s, string p, int i, int j) {
        if(i < 0 && j < 0) return true;
        if(j < 0) return false;

        if(memo[i+1][j+1] >= 0) return memo[i+1][j+1];
        
        if(i >= 0 && (s[i] == p[j] || p[j] == '.')) {
            memo[i+1][j+1] = isMatch(s, p, i-1, j-1);
            return memo[i+1][j+1];
        }

        if(p[j] == '*') {
            bool c0 = isMatch(s, p, i, j-2);
            bool c1 = i >= 0 ? isMatch(s, p, i, j-1) : false;
            bool c2 = i >= 1 ? isMatch(s, p, i-1, j) && (s[i] == p[j-1] || p[j-1] == '.') : false;
            memo[i+1][j+1] = (c1 || c0 || c2);
            return memo[i+1][j+1];
        }
        memo[i+1][j+1] = 0;
        return memo[i+1][j+1];
    }
};

class Solution3 {
    /*
     * Recursion with memoization.
     *      if s[i] == p[j] or p[j] == '.' --> isMatch(i, j) = isMatch(i-1, j-1)
     *      if s[i] != p[j] and p[j] != '*':
     *              --> isMatch(i, j) = False
     *      if p[j] == '*':
     *              --> isMatch(i, j) = isMatch(i, j-1) # single precedding character
     *              --> isMatch(i, j) = isMatch(i, j-2) # zero preceeding character
     *              --> isMatch(i, j) = isMatch(i-1, j) and (s[i] == p[j-1] || p[j-1] == '.') ## multiple preceeding characters
     * 
     * add Memoization
     *      duplicates: isMatch(i, j)
     *                                                                                                                                                                                                                                                                   
     * Dynamic programming
     *      if s[i] == p[j] || p[j] == '.' --> dp[i][j] = dp[i-1][j-1]
     *      if s[i] != p[j] && p[j] != '*':
     *              --> dp[i][j] = False                                                                           
     *      if p[j] == '*':
     *              --> dp[i][j] = dp[i][j-1] # single preceeding character
     *              --> dp[i][j] = dp[i][j-2] # zero preceding character
     *              --> dp[i][j] = dp[i-1][j] and (s[i] == p[j-1] || p[j-1] == '.') ## multiple preceeding characters
     */
    
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i == 0 ? 1 : 0;
        }

        for(int j = 2; j <= n; j+=2) {
            dp[0][j] = p[j-1] == '*' ? 1 : 0;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '.') 
                    dp[i][j] = dp[i-1][j-1];
                if(p[j-1] == '*'){
                    bool c0 = dp[i][j-2];
                    bool c1 = dp[i][j-1];
                    bool c2 = i >= 1 ? dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.') : false;
                    dp[i][j] = c0 || c1 || c2;
                }
            }
        }
        return dp[m][n];
    }
};



int main() {
    string s = "aa";
    string p = ".*";
    bool ans = Solution3().isMatch(s, p);
    cout << ans;
}