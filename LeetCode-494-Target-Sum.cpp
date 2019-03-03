#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
    // dfs recursive solution O(2^N) in time, O(1) in space
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums, S, 0);
    }

    int helper(vector<int>& nums, int S, int i) {
        if(i == nums.size() && S == 0) return 1;
        else if(i == nums.size()) return 0;
        return helper(nums, S+nums[i], i+1) + helper(nums, S-nums[i], i+1);
    }
};

class Solution2 {
    // convert the problem to 
    // finding number of subsets that add up to (sum(nums) + S) //2 
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // vector<vector<int>> memo{nums.size(), vector<int>(S+1, -1)};

        // compute the sum of nums
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (sum + S) % 2 != 0) return 0;
        return subsetSum(nums, (sum + S) / 2, 0);
    }

    int subsetSum(vector<int>& nums, int S, int i) {
        if(i <= nums.size() && S == 0) return 1;
        if(i >= nums.size() || S < 0) return 0;
        
        // two options: either include the num[i] or skip the num[i]
        return subsetSum(nums, S - nums[i], i + 1) + subsetSum(nums, S, i + 1);
    }
};

class Solution3 {
    // recursive solution with memoization
public:
    int findTargetSumWays(vector<int>& nums, int S) { 
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(S > sum || S < -sum || (sum + S) % 2 != 0) return 0;

        vector<vector<int>> memo{nums.size(), vector<int>((sum+S)/2+1, -1)};
        return subsetSum(nums, (sum+S) / 2, 0, memo);
    }

    int subsetSum(vector<int>& nums, int S, int i, vector<vector<int>>& memo) {
        if(i == nums.size() && S == 0) return 1;
        if(i >= nums.size() || S < 0) return 0;
        
        if(memo[i][S] >= 0) return memo[i][S];
        else memo[i][S] = subsetSum(nums, S-nums[i], i+1, memo) + subsetSum(nums, S, i+1, memo);
        return memo[i][S];
    }
};

class Solution4 {
    // iterative solution form soluion, O((sum(nums) + S)/2 * N) -> O(S*N), O(S*N) in space
    // bottom-up and top-down are mostly similar when "time complexity = space complexity"
    // sometimes one of them would not work if we are going to lower down the dimension
    // then choice of these two are determined by the position of initial value
public:
    int findTargetSumWays(vector<int>& nums, int S) {  
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || S < -sum || (sum + S) % 2 != 0) return 0;
        int N = (sum+S) / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(N, 0)); 
        memo[0][0] = 1;
        if(nums[0] <= N) memo[0][nums[0]] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j <= (sum+S)/2; j++){
                if(j >= nums[i])
                    memo[i][j] = memo[i-1][j-nums[i]] + memo[i-1][j];
                else
                    memo[i][j] = memo[i-1][j];
            }
        }
        return memo[(int)nums.size()][N];
    }
};


int main(){
    vector<int> nums{1, 1, 1, 1, 1};
    int S = 3;
    int ans = Solution4().findTargetSumWays(nums, S);
    cout << ans << "\n";
    return 0;
 };