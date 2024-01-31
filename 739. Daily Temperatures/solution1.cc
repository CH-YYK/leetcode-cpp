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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // find next higher
        // monotonic increasing stack
        //  1. loop from right to left, keep the stack decreasing
        //  2, pop the stack when temp[i] >= temp[stk.top()], 
        //     then the last temp[stk.top()] is the next higher
        // Time: O(N)
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n, 0);
        for(int i = n -1; i >= 0; --i) {
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()])
                stk.pop();
            if(!stk.empty())
                ans[i] = stk.top() - i;
            stk.push(i);
        }
        return ans;
    }
};