#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index;
        for(int i = 0; i < nums.size(); i++){
            index = abs(nums[i]) - 1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }

        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};