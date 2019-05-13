#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        if(n == 0) return "";

        int l = 0;
        string res = "";

        vector<int> cnt(26, 0);
        for(int i = 0; i < n; i++) 
            cnt[s[i]- 'a'] = 1;
        int total_diff = accumulate(cnt.begin(), cnt.end(), 0);
        
        // int total_diff = 0;
        // for_each(cnt.begin(), cnt.end(), [&](int x) {total_diff += x;});

        for(int z = 0; z < total_diff; z++) 
            for(int i = 0; i < 26; i++) {
                int appear = -1;
                for(int j = l; j < n; j ++) 
                    if(s[j] - 'a' == i && res.find('a' + i) == -1) {
                        appear = j;
                        break;
                    }

                if(appear == -1) continue;

                vector<int> cnt2(26, 0);
                for(int j = appear; j < n; j++) 
                    cnt2[s[j] - 'a'] = 1;
                for(auto c: res) 
                    cnt2[c - 'a'] = 1;
                int s = accumulate(cnt2.begin(), cnt2.end(), 0);
                if(s == total_diff) {
                    res += char('a' + i);
                    l = appear + 1;
                    break;
                }
            }
        return res;
    }
};