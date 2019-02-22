#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int i = 0;
        while(i < nums.size() && nums[i] < target) i++;
        return i;
    }
};