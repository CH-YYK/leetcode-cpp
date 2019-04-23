#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> index;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            while(!index.empty() && nums[i] > nums[index.back()]) index.pop_back();
            index.push_back(i);
            if(i - k + 1 >= 0) ans.push_back(nums[index.front()]);
            if(i - k + 1 >= index.front()) index.pop_front();
        }
        return ans;
    }
};