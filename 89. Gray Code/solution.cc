#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int max_ = (1 << n) - 1, prev = 0;
        vector<int> visited(max_ + 1, 0);
        vector<int> res{0};
        visited[0] = 1;
        prev = 0;
        while(res.size() < (1 << n)) {
            int num = res.back();
            for(int i = 0; i < n; ++i) {  // stop when the first i-th bit will be changed
                if(num & (1 << i)) { // i-th bit is 1 and change it to 0
                    int nextnum = num & ~(1 << i);  // flip 1 at i-th to 0
                    if(visited[nextnum]) continue;
                    res.push_back(nextnum);
                    prev = num;
                    visited[nextnum] = 1;
                    break;
                } else { // i-th bit is 0 and change it to 1
                    int nextnum = num | (1 << i);  // flip 0 at i-th to 1
                    if(visited[nextnum]) continue;
                    res.push_back(nextnum);
                    visited[nextnum] = 1;
                    break;
                }
            }
        }
        return res;
    }
};
