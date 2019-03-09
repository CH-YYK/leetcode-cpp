#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &i : wordDict) WordDict.insert(i);
        return helper(s, 0);
    };
private:
    unordered_map<int, bool> memo;
    unordered_set<string> WordDict;
    bool helper(string &s, int i) {
        if(i == s.size()) return true;
        if(memo.count(i)) return memo[i];
        bool cond = false;
        for(int j = i; j < s.size(); j++)
            cond = cond || (WordDict.count(s.substr(i, j-i+1)) && helper(s, j+1));
        memo[i] = cond;
        return memo[i];
    }
};