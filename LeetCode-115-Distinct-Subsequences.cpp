#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    // pure recusion version: 2 ^ N.
public:
    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        return numWays(s, t, 0, 0);
    }
private:
    int m, n;
    int numWays(string &s, string &t, int i, int j) {
        if(j == n) return 1;
        
        if(m - i == n - j) 
            return s[i] == t[j] ? numWays(s, t, i + 1, j + 1) : 0;
        
        if(s[i] == t[j]) 
            return numWays(s, t, i+1, j+1) + numWays(s, t, i+1, j);
        else
            return numWays(s, t, i+1, j);
    }
};

class Solution2 {
    // memoization
public:
    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        if(m == 0) return 0;
        memo = vector<vector<int>> (m, vector<int>(n, -1));
        return numWays(s, t, 0, 0);
    }
private:
    int m, n;
    vector<vector<int>> memo;

    int numWays(string &s, string &t, int i, int j) {
        if(j == n) return 1;
        
        if(memo[i][j] >= 0) return memo[i][j];

        if(m - i < n - j)
            memo[i][j] = 0;
        else if(m - i == n - j)
            memo[i][j] = s[i] == t[j] ? numWays(s, t, i + 1, j + 1) : 0;
        else if(s[i] == t[j]) 
            memo[i][j] = numWays(s, t, i+1, j+1) + numWays(s, t, i+1, j);
        else
            memo[i][j] = numWays(s, t, i+1, j);
        return memo[i][j];
    }
};


class Solution3 {
    // memo[i][j] : number of ways to change s[:i] to t[:j]
public:
    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        if(m == 0) return 0;
        memo = vector<vector<long>> (m+1, vector<long>(n+1, 0));
        
        for(int i = 0; i <= m; i++) 
            memo[i][0] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == t[j-1]) 
                    memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
                else
                    memo[i][j] = memo[i-1][j];                
            }
        }
        return memo[m][n];
    }
private:
    int m, n;
    vector<vector<long>> memo;
};


