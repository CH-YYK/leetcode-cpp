#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // answer0: all win->no lose
        // answer1: 1 lose
        unordered_map<int,int> lost;
        for(auto& match : matches) {
            lost[match[1]]++;
            if(!lost.count(match[0]))
                lost[match[0]] = 0;
        }
        
        vector<vector<int>> ans(2);
        for(auto& it : lost) {
            if(it.second == 1)
                ans[1].push_back(it.first);
            else if(it.second == 0)
                ans[0].push_back(it.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};