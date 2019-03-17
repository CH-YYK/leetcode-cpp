#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
    // brute force way O(2^n)
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), [](const int x, const int y){return x < y;});
        targetsum = target;
        dfs(nums, 0, subset, 0);
        
        vector<vector<int>> ans;
        ans.assign(all_subsets.begin(), all_subsets.end());
        return ans;
    }
private:
    set<vector<int>> all_subsets;
    vector<int> subset;
    int targetsum;

    void dfs(vector<int> &nums, int index, vector<int> &subset, int sum) {
        if(subset.size() == 4) {
            if(sum == targetsum) 
                all_subsets.insert(subset);
            return;
        }else if(index == nums.size()) return ;

        subset.push_back(nums[index]);
        dfs(nums, index+1, subset, sum+nums[index]);
        subset.pop_back();
        dfs(nums, index+1, subset, sum);
    }
};

class Solution2 {
    // modified binary search, O(n^3)
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> all_subsets;
        
        for(int i = 0; i < nums.size() - 3; i++) {
            // avoid duplicated i
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i; j < nums.size()-2; j++) {
                // avoid duplicated j
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                // start two iterators search        
                int sum = target - nums[i] - nums[j];
                int a = j+1, b = nums.size() - 1;
                while(a < b) {
                    if(nums[a] + nums[b] > sum)
                        b--;
                    else if(nums[a] + nums[b] < sum)
                        a++;
                    else{
                        all_subsets.push_back({nums[i], nums[j], nums[a], nums[b]});
                        while(a < b && nums[a++] == nums[a]);
                        while(a < b && nums[b--] == nums[b]);
                    }
                }
            }
        }
        return all_subsets;
    }  
};

int main() {

    vector<int> nums = {-5, -4, -3, -2, 1, 3, 3, 5};
    int target = -11;
    vector<vector<int>> all_subsets = Solution2().fourSum(nums, -11);
}