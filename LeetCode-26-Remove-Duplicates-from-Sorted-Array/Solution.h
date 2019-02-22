#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // modifying values in the raw vector
        if(nums.size() < 2) return (int)nums.size();
        int index = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[index]){
                index++;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
};