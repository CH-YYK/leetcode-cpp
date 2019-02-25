#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonSubsequence(string& str1, string& str2) {
        return dfs(str1, str2, 0, 0);
    }
    string dfs(string& str1, string& str2, int i, int j) {
        if(i >= str1.size() || j >= str2.size()) return "";
        if(str1[i] == str2[j]) return str1[i] + dfs(str1, str2, i+1, j+1);
        return max(dfs(str1, str2, i+1, j), dfs(str1, str2, i, j+1));
    }
};

class Solution2 {
public:
    string longestCommonSubsequence(string& str1, string& str2) {
        memo = vector<vector<string>>(str1.size(), vector<string>(str2.size(), ""));
        return dfs(str1, str2, 0, 0);
    }
private:
    vector<vector<string>> memo;
    string dfs(string& str1, string& str2, int i, int j) {
        if(i >= str1.size() || j >= str2.size()) return "";
        if(!memo[i][j].empty()) return memo[i][j];
        if(str1[i] == str2[j]){
            memo[i][j] = str1[i] + dfs(str1, str2, i+1, j+1);            
             return memo[i][j];
        }
        memo[i][j] = max(dfs(str1, str2, i+1, j), dfs(str1, str2, i, j+1));
        return memo[i][j];
    }
};

int main() {
    string str1 = "hello world";
    string str2 = "hello you";
    string ans = Solution2().longestCommonSubsequence(str1, str2);
    for(auto i: ans) cout << i << " ";
    cout << "\n";
    return 0;
}