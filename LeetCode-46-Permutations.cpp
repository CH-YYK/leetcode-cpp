#include <vector>
#include <iostream>
using namespace std;

class Solution {
    // bit manipulation for index
public:
    vector<vector<int>> permute(vector<int>& nums) {
        indexset = 1 << nums.size();
        dfs(nums, 0, comb);
        return res;
    };
private:
    int indexset;
    vector<vector<int>> res;
    vector<int> comb;

    void dfs(vector<int>& nums, int index, vector<int>& comb) {
        if((indexset & (indexset + 1)) == 0) {
            res.push_back(comb);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if((indexset & (1 << i)) > 0) continue;
            indexset = indexset | (1 << i);
            comb.push_back(nums[i]);
            dfs(nums, i, comb);
            comb.pop_back();
            indexset -= (1 << i);
        }
    }
};

int main() {
    vector<int> nums({1,2,3});
    vector<vector<int>> ans = Solution().permute(nums);
    for(auto i : ans) {
        for(auto j : i) 
            cout << j << " ";
        cout << "\n";
    }
}