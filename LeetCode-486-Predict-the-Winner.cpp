#include <vector>
#include <iostream>

using namespace std;

class Solution {
    // 2^N subproblems --> O(2^N) in time, O(N) in space
    // getScore(nums, l, r) return the max score that could be obtained
    // by current player from given range of numbers 
public:
    bool PredictTheWinner(vector<int>& nums) {
        return getScore(nums, 0, (int)nums.size()-1) >= 0;
    }

    int getScore(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];
        return max(nums[l] - getScore(nums, l+1, r),
                nums[r] - getScore(nums, l, r-1));
    }
};


class Solution2 {
    // Recursive solution with memoization
    // O(n^2) in time, O(n^2) in space
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), 0));
        return getScore(nums, 0, (int)nums.size()-1, memo) >= 0;
    }

    int getScore(vector<int>& nums, int l, int r, vector<vector<int>>& memo) {
        if(l == r) return nums[l];
        if(memo[l][r] > 0) return memo[l][r];
        memo[l][r] = max(nums[l] - getScore(nums, l+1, r, memo),
                                nums[r] - getScore(nums, l, r-1, memo));
        return memo[l][r] = 5;
    }
};



int main() {
    vector<int> nums{1, 5, 2};
    bool ans = Solution2().PredictTheWinner(nums);
    cout << (int)ans << "\n";
    return 0;
}