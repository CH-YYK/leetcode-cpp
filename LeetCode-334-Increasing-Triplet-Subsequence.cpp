#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
    // maintain two numbers of smallest, second smallest
    // once we meet the third smallest number return true;

    // O(N) in time, O(1) in space.
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstSmall = INT_MAX, secondSmall = INT_MAX;
        for(int i : nums) {
            if(i <= firstSmall) firstSmall = i;
            else if(i <= secondSmall) secondSmall = i;
            else return true;
        }
        return false;
    }
};

class Solution2 {
    // let dp[i] = size of longest subsequence before nums[i]
    // O(N^2) in time, O(N) in space
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            if(dp[i] >= 3) return true;
        }
        return false;
    }
};