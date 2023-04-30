// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // sliding window
        // processing a word one by one and move l by word.length
        // 
        // since starting l from 0 may lose some cases
        // try starting l from 0 ~ len to cover all cases.
        unordered_map<string, int> dict;
        for(string& w : words)
            dict[w]++;
        int n = s.size(), m = words.size(), len = words[0].size();
        vector<int> ans;

        for(int i = 0; i < len; ++i) {
            int l = i;
            int cnt = dict.size();
            unordered_map<string, int> copy = dict;
            for(int r = l; r <= n - len; r += len) {
                string w = s.substr(r, len);
                if(copy.count(w)) {
                    if(--copy[w] == 0)
                        copy.erase(w);                
                } else if(dict.count(w)) {
                    while(l < r && s.substr(l, len) != w) {
                        copy[s.substr(l, len)]++;
                        l += len;
                    }
                    l += len;
                } else {
                    while(l < r) {
                        copy[s.substr(l, len)]++;
                        l += len;
                    }
                    l += len;
                }

                if(copy.empty()) {
                    ans.push_back(l);
                    copy[s.substr(l, len)]++;
                    l += len;
                }
            }
        }
        return ans;
    }
};