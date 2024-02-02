#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // just construct all possible numbers and save the valid ones
        // At most O(9^9).
        for(int i = 0; i <= 9; ++i) {
            dfs(i, low, high);
        }
        return vector<int>(ans.begin(), ans.end());
    }
private:
    set<int> ans;
    void dfs(long num, int low, int high) {
        if(num > high) 
            return ;
        if(num >= low) {
            ans.insert(num);
        }
        int d = num % 10 + 1;
        if(d < 10)
            dfs(10 * num + d, low, high);
    }
};
