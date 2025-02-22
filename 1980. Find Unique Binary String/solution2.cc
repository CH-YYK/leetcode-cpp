#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        // This question is similar to find a number that is not in the array.
        // Since we only need any of them, it could be the one that is greater than the max or the one that is less than the min.
        // But it has to be in the range of [0000, 1111], if n = 4.
        //
        // So we always start from [0]{n} and then take the max.
        int n = nums[0].size();
        string res = "";
        for (int i = 0; i < n; i++) {
            res += (1 ^ (nums[i][i] - '0')) + '0';
        }
        return res;
    }
};