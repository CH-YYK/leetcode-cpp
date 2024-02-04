#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // using sliding window, 
        // we don't care about the order in t.
        //
        // create the window to track t's chars only.
        // use two vector of characters to justify the state of sliding window.
        int l = 0, cnt = 0, len = s.size() + 1, minL = 0;
        vector<int> chars(128, 0), win(128, 0);
        for(char c : t) chars[c]++;

        for(int r = 0; r < s.size(); ++r) {
            if(chars[s[r]] > 0) {
                if(win[s[r]] < chars[s[r]])
                    cnt++;
                win[s[r]]++;
            }
            
            while(cnt == t.size()) {
                if(chars[s[l]] > 0 && win[s[l]] == chars[s[l]])
                    cnt--;
                if(r - l + 1 < len) {
                    len = r - l + 1;
                    minL = l;
                }
                win[s[l++]]--;
            }
        }
        return len > s.size() ? "" : s.substr(minL, len);
    }
};