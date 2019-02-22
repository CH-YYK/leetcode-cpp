// dynamic programming (bottom-up) with arrays

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution4 {
public:
    int longestPalindromeSubseq(string s) {
        int n = (int)s.size();
        int memo[n][n];
        for(int l = 1; l <= s.size(); l++){
            for(int i = 0; i < s.size() - l + 1; i++){
                int j = i+l-1;
                if(i == j) memo[i][j] = 1;
                // to avoid undefined value at memo[i+1][j-1] in second iteration
                else if(s[i] == s[j] && l == 2) memo[i][j] = 2;
                else if(s[i] == s[j]) memo[i][j] = 2 + memo[i+1][j-1];
                else memo[i][j] = max(memo[i+1][j], memo[i][j-1]);
                // printf("i: %d, j: %d, value: %d \n", i, j, memo[i][j]);
            }
        }
        return memo[0][n-1];
    }
};