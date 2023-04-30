// recursive solution with memory (top-down)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size()));
        // for(int i=0; i<s.size(); i++) memo[i][i] = 1;
        return this->dfsHelper(s, 0, (int)s.size()-1, memo);
        // for(auto j:memo) std::cout << j[s.size()-1] << "\n";
        // return memo[0][s.size() - 1];
    }

private:
    // using address of string would save memory given that we don't need to modify s
    int dfsHelper(const string &s, int i, int j, vector<vector<int>> &memo) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(memo[i][j]) return memo[i][j];
        if(s[i] == s[j]) return 2 + this->dfsHelper(s, i+1, j-1, memo);
        else{
            int l1 = this->dfsHelper(s, i+1, j, memo);
            int l2 = this->dfsHelper(s, i, j-1, memo);
            memo[i][j] = l1 > l2 ? l1 : l2;
            return memo[i][j];
        }
    }
};