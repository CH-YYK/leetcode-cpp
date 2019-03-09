#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, 0, path, target);
        return all;
    };
private:
    vector<vector<int>> all;
    vector<int> path;
    void helper(vector<int> &candidates, int index, vector<int> &path, int target){
        if(target == 0){
            all.push_back(path);
            return;
        }
        if(target < 0) {
            return;
        }
        for(int j = index; j < candidates.size(); j++) {
            path.push_back(candidates[j]);
            helper(candidates, j, path, target - candidates[j]);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates({2, 3, 6, 7});
    int target = 7;
    vector<vector<int>> ans = Solution().combinationSum(candidates, target);
    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}