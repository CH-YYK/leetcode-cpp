/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // distribution must match, no additional chars are added
        // distinct chars must match
        if(word1.size() != word2.size())
            return false;
        int n = word1.size();
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < n; ++i) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }
        for(int i = 0; i < 26; ++i) {
            if((freq1[i] > 0) ^ (freq2[i] > 0))
                return false;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};
// @lc code=end

