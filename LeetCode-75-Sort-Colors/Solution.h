#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        DividList(nums, 0, (int)nums.size()-1);
    }

    void mergeList(vector<int>& nums, int l, int m, int r){
        if(l <= m && m < r){
            if(nums[l] <= nums[m+1]) mergeList(nums, l+1, m, r);
            else{
                int tmp = nums[m+1];
                for(int i = (int)nums.size()-1; i > l ; i--)
                    nums[i] = nums[i-1];
                nums[l] = tmp;
                mergeList(nums, l+1, m+1, r);
            }
        }
    }

    void DividList(vector<int>& nums, int l, int r){
        if(l < r){
            int m = (l + r) / 2;
            DividList(nums, l, m);
            DividList(nums, m+1, r);
            mergeList(nums, l, m, r);
        }
    }
};