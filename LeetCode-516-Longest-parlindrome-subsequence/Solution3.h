// dynamic programming (bottom-up) with vectors

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution3 {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), 0));
        for(int l = 1; l <= s.size(); l++){
            for(int i = 0; i < s.size() - l + 1; i++){
                int j = i+l-1;
                if(i == j) memo[i][j] = 1;
                else if(s[i] == s[j]) memo[i][j] = 2 + memo[i+1][j-1];
                else memo[i][j] = max(memo[i+1][j], memo[i][j-1]);
            }
        }
        return memo[0][s.size()-1];
    }
};