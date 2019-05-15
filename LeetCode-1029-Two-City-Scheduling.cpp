#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(vector<int> & lhs, vector<int> & rhs) {
        return lhs[0] - lhs[1] < rhs[0] - rhs[1];
    }
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp = [](const vector<int>lhs, const vector<int>rhs) 
            {return lhs[0]-lhs[1] < rhs[0]-rhs[1];};
        sort(costs.begin(), costs.end(), cmp);
        int N = costs.size() / 2;
        int sum = 0;
        for(int i = 0; i < 2 * N; i++) {
            if(i < N) sum += costs[i][0];
            else sum += costs[i][1];
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> costs = {{10, 30}};
    auto ans = Solution().twoCitySchedCost(costs);
    cout << ans;
}