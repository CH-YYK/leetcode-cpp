#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
       // abcdab, baceb, abacedab
        // find longest common subsequence
        // find the locations of characters in the LCS <index in str,index in subsequnce>
        // 
        // ['', 'b', 'c', 'b'], [['a'], ['a'], ['e', 'd', 'a'], []]
        
        // Find LCS
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<string>> dp(n1 + 1, vector<int>(n2+1, "")); // path in str1
        vector<int> prechar(n1, -1);  // mark the selected characters in str1
        for(int i = 0; i < n1; ++i)
          for(int j = 0; j < n2; ++j)
            if(str1[i] == str2[j]) {
              dp[i+1][j+1] = dp[i][j] + str1[i];
            } else {
              if(dp[i][j+1].size() > dp[i+1][j].size())
                dp[i+1][j+1] = dp[i][j+1];
              else
                dp[i+1][j+1] = dp[i+1][j];
            }
        string lcs = dp[n1][n2];
        string res;
        int i = 0, j = 0;
        for (char c : lcs) {
          while (str1[i] != c)
            res += str1[i++];
          while(str2[j] != c)
            res += str2[j++1];
          lcs += c;
        }
        return lcs + str1.substr(i) + str2.substr(j);
    }
};
