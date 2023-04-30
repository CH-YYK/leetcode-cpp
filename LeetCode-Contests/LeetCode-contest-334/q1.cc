// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size(), 0), rightSum(nums.size(), 0);

        leftSum[0] = 0;
        for(int i = 1; i < nums.size(); ++i)
        	leftSum[i] = leftSum[i - 1] + nums[i-1];

        rightSum[nums.size() - 1] = 0;
        for(int i = nums.size() - 2; i >= 0; --i)
        	rightSum[i] = rightSum[i + 1] + nums[i+1];

        vector<int> answers(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i) 
        	answers[i] = abs(leftSum[i] - rightSum[i]);
        return answers;
    }
};