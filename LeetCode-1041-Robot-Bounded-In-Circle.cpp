#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int * p = &y;
        int sign = 1;

        for(char c : (instructions+instructions+instructions+instructions)) {
            if(c == 'G') {
                *p += sign;
                continue;
            }
            if(c == 'L') {
                if(p == &y) p = &x, sign *= -1;
                else if(p == &x) p = &y;
            }
            else {
                if(p == &y) p = &x;
                else if(p == &x) p = &y, sign *= -1;
            }
        }
        return x ==0 && y == 0;
    }
};

int main() {
    string instruction = "GGLLGG";
    bool ans = Solution().isRobotBounded(instruction);
    cout << ans << endl;
}