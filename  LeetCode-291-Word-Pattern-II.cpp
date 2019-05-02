#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        return dfs(pattern, str, 0, 0);
    }
private:
    unordered_map<char, string> memo;
    unordered_set<string> seen;

    bool dfs(string &pattern, string &str, int i, int j) {
        if(i == pattern.size() && j == str.size()) 
            return true;
        if(i == pattern.size() || j == str.size()) 
            return false;
        
        if(memo.count(pattern[i])) {
            string p = memo[pattern[i]];
            return p == str.substr(j, p.size()) && dfs(pattern, str, i + 1, j + p.size());        
        }

        for(int k = 1; k <= str.size() - j - pattern.size() + i + 1; ++k) {
            string p = str.substr(j, k);
            if(seen.count(p))
                continue;
            memo[pattern[i]] = p;
            seen.insert(p);
            if(dfs(pattern, str, i + 1, j+k)) 
                return true;
            memo.erase(pattern[i]);
            seen.erase(p);
        }
        return false;
    }
};