#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        // partition the colors to various adjacent partitions of consecutive colors.
        // the minimum cost of each partition is (sum - max).
        //  Time: O(N)
        int i = 0, ans = 0;
        while(i < n) {
            int j = i+1;
            int maxtime = neededTime[i];
            int sum = maxtime;
            while(j < n && colors[j] == colors[i]) {
                maxtime = max(maxtime, neededTime[j]);
                sum += neededTime[j];
                j++;
            }
            if(sum > maxtime)
                ans += sum - maxtime;
            i = j;
        }
        return ans;
    }
};