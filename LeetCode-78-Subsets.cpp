#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, 0, path);
        return all_subsets;
    }
private:
    vector<vector<int>> all_subsets;

    void dfs(vector<int>& nums, int ind, vector<int>& path) {
        if(ind == nums.size()) {
            all_subsets.push_back(path);
            return;
        }
        path.push_back(nums[ind]);
        dfs(nums, ind+1, path);
        path.pop_back();
        dfs(nums, ind+1, path);
    }
};