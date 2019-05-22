#include <vector>
#include <iostream>
using namespace std;

class Solution {
    
public:
    int integerBreak(int n) {
        if(n == 1) return n;
        int maxmum = 0;
        for(int i = 1; i < n; i++) {
            maxmum = max(maxmum, integerBreak(i) * integerBreak(n-i));
        }
        return max(n, maxmum);
    }    
};

class Solution2 {
public:
    int integerBreak(int n) {
        memo = vector<int>(n, 0);
        int maxmum = 0;
        for(int i = 1; i < n; i++) 
            maxmum = max(maxmum, helper(i) * helper(n-i));
        return maxmum;
    }
private:
    vector<int> memo;
    int helper(int n) {
        if(n == 1) return n;
        if(memo[n-1] > 0) return memo[n-1];

        int maxmum = 0;
        for(int i = 2; i < n; i++) 
            maxmum = max(maxmum, helper(i) * helper(n-i));
        memo[n-1] = max(maxmum, n);
        return memo[n-1];
    }
};

int main() {
    int n = 10;
    int ans = Solution2().integerBreak(10);
    cout << ans << endl;
}