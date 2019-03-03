#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution {
    // recursive solution: O(K^N) 
public:
    int jump(vector<int>& nums) {
        return helper(nums, 0);
    }

    int helper(vector<int>& nums, int i) {
        if(i >= nums.size() - 1) return 0;
        int minVal = INT_MAX;
        for(int j = 1; j <= nums[i]; j++)
            minVal = min(minVal, helper(nums, i+j));
        if(minVal < INT_MAX) return 1 + minVal;
        else return minVal;
    }   
};

class Solution2 {
    // recursive solution with memoization O(n)
public:
    int jump(vector<int>& nums) {
        unordered_map<int, int> memo;
        return helper(nums, 0, memo);
    }

    int helper(vector<int>& nums, int i, unordered_map<int, int>& memo) {
        if(i >= nums.size() - 1) return 0;
        if(memo.count(i)) return memo[i];
        int minVal = INT_MAX;
        for(int j = 1; j <= nums[i]; j++) 
            minVal = min(minVal, helper(nums, i+j, memo));
        if(minVal < INT_MAX) memo[i] = 1 + minVal;
        else memo[i] = minVal;
        return memo[i];
    }
};

class Solution3 {
    // dynamic programming: O(nk), O(N) in space
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int j = nums.size()-2; j >= 0; j--){
            if(j + nums[j] >= nums.size()-1) dp[j] = 1;
            else{
                int minVal = INT_MAX;
                for(int i = j+1; i <= j + nums[j]; i++)
                    minVal = min(minVal, dp[i]);
                dp[j] = minVal < INT_MAX ? minVal + 1 : INT_MAX;
            }
        }
        return dp[0];
    }
};

class Solution4 {
    // Greedy algorithm O(N) O(N)
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, step = 0, maxend = 0, n = (int)nums.size();
        while(end < n-1) {
            step++;
            for(int j = start; j <= end; j++){
                if(j + nums[j] >= n-1) return step;
                maxend = max(j + nums[j], maxend);
            }
            start = end + 1;
            end = maxend;
        }
        return step;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    // int ans = Solution3().jump(nums);
    int ans = Solution4().jump(nums);
    cout << ans << "\n";    
    return 0;
}

