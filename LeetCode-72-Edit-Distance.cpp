#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    /* without memoization
     * go through two strings from left to right
     *      set two pointer i,j
     *      if s1[i] == s2[j] --> minDis(s1, s2, i+1, j+1) = minDis(s1, s2, i, j)
     *      if s1[i] != s2[j] --> minDis(s1, s2, i+1, j) = 1 + minDis(s1, s2, i, j) ## remove s1[i]
     *                            minDis(s1, s2, i+1, j+1) = 1 + minDis(s1, s2, i, j) ## substitute s1[i]
     *                            minDis(s1, s2, i, j+1) = 1 + minDis(s1, s2, i, j) ## insert a new character
    */
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        return minDistance(word1, word2, 0, 0);
    }
private:
    int minDistance(string word1, string word2, int i, int j) {
        if(i == word1.size() || j == word2.size()) return word1.size() + word2.size() - i - j;
        if(word1[i] == word2[j]) return minDistance(word1, word2, i+1, j+1);
        else {
            int rm = minDistance(word1, word2, i+1, j);
            int sub = minDistance(word1, word2, i+1, j+1);
            int ins = minDistance(word1, word2, i, j+1);
            return min(ins, min(sub, rm)) + 1;
        }
    }
};

class Solution2 {
    /* with memoization
     * go through two strings from left to right
     *      set two pointer i,j
     *      if s1[i] == s2[j] --> minDis(s1, s2, i+1, j+1) = minDis(s1, s2, i, j)
     *      if s1[i] != s2[j] --> minDis(s1, s2, i+1, j) = 1 + minDis(s1, s2, i, j) ## remove s1[i]
     *                            minDis(s1, s2, i+1, j+1) = 1 + minDis(s1, s2, i, j) ## substitute s1[i]
     *                            minDis(s1, s2, i, j+1) = 1 + minDis(s1, s2, i, j) ## insert a new character
     * 
     * add memoization: log of index i,j
     *      matrix[i][j]
    */
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        memo = vector<vector<int>> (word1.size(), vector<int>(word2.size(), -1));
        return minDistance(word1, word2, 0, 0);
    }
private:
    vector<vector<int>> memo;

    int minDistance(string word1, string word2, int i, int j) {
        if(i == word1.size() || j == word2.size()) return word1.size() + word2.size() - i - j;

        // check memoization
        if(memo[i][j] >= 0) return memo[i][j];

        if(word1[i] == word2[j]) return minDistance(word1, word2, i+1, j+1);
        else {
            int rm = minDistance(word1, word2, i+1, j);
            int sub = minDistance(word1, word2, i+1, j+1);
            int ins = minDistance(word1, word2, i, j+1);
            memo[i][j] = min(ins, min(sub, rm)) + 1;
        }
        return memo[i][j];
    }
};

class Solution3 {
    /* dynamic programming
     * go through two strings from left to right
     *      set two pointer i,j
     *      if s1[i] == s2[j] --> minDis(s1, s2, i+1, j+1) = minDis(s1, s2, i, j)
     *      if s1[i] != s2[j] --> minDis(s1, s2, i+1, j) = 1 + minDis(s1, s2, i, j) ## remove s1[i]
     *                            minDis(s1, s2, i+1, j+1) = 1 + minDis(s1, s2, i, j) ## substitute s1[i]
     *                            minDis(s1, s2, i, j+1) = 1 + minDis(s1, s2, i, j) ## insert a new character
     * 
     * add memoization: log of index i,j
     *      matrix[i][j]
     * 
     * convert to DP
     *      if s1[i] == s2[j] --> dp[i+1][j+1] = dp[i][j]   --> dp[i][j] = dp[i+1][j+1]
     *      if s1[i] != s2[j] --> dp[i+1][j] = dp[i][j]     --> dp[i][j] = dp[i+1][j]
     *                        --> dp[i+1][j+1] = dp[i][j]   --> dp[i][j] = dp[i+1][j+1]
     *                        --> dp[i][j+1] = dp[i][j]     --> dp[i][j] = dp[i][j+1]
    */
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        
        for(int i = 0; i <= m; i++) {
            dp[i][n] = m - i;
        }
        for(int j = 0; j <= n; j++) {
            dp[m][j] = n - j;
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(word1[i] == word2[j]) 
                    dp[i][j] = dp[i+1][j+1];
                else {
                    /* int rm = dp[i+1][j];
                     * int sub = dp[i+1][j+1];
                     * int ins = dp[i][j+1];
                     * dp[i][j] = min(rm, min(sub, ins)) + 1;
                    */
                    dp[i][j] = min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};
