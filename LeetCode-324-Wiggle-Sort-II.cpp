#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            res.push_back(nums[i++]);
            res.push_back(nums[j--]);
        }
        nums = res;
    }
};