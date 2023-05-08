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
    int minIncrements(int n, vector<int>& cost) {
        // each leaf unqiuely represent a path from root
        // In a perfect binary tree, a leaf node i can be found by check 2*i >= n
        int max_ = 0;
        int cnt = 0;
        vector<int> diff(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            int ind = i + 1;
            if (i > 0)
                cost[i] += cost[ind / 2 - 1];
            if (2 * ind >= n) {
                max_ = max(max_, cost[i]);
                cnt++;
                diff[i] = -cost[i];
            }
        }
        for (int i = n - 1; i >= 0 && diff[i] != INT_MAX; --i) {
            diff[i] += max_;
        }

        // push the diff to the common ancestor
        for (int i = n / 2 - 1; i > 0; --i) {
            int ind = i + 1;
            int child1 = ind * 2 - 1;
            int child2 = ind * 2;
            diff[i] = min(diff[child1], diff[child2]);
            diff[child1] -= diff[i];
            diff[child2] -= diff[i];
        }

        // back-propagate the diff in common ancestor back to children
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (diff[i] == INT_MAX) continue;
            int ind = i + 1;
            ans += diff[i];
        }
        return ans;
    }
};