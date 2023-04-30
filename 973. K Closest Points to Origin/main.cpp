#include <iostream>
#include "Solution.h"
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> nums{{-2, 2}, {1, 3}, {0,0}};
    vector<vector<int>> ans = Solution().kClosest(nums, 1);
    for(vector<int> i:ans) {
        for (int j:i) cout << j << ' ';
        cout << '\n';
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}