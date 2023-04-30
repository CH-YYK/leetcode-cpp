#include <iostream>
#include "Solution.h"
#include <vector>

using namespace std;

int main() {
    vector<int> nums{ -6, -4, -2, -1 };
    // cout << " " << nums[20];
    vector<int> ans = Solution().sortedSquares(nums);
    for(int i:ans) cout << " " << i;
    cout << endl;
    return 0;
}