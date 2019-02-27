#include <vector>
#include <string> 
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
    // Brute force solution  O(n^2)
    // divide string into two parts. Count and store the number of ways needed
    // to flip 0->1 left and 1->0 right
public:
    int minFlipsMonoIncr(string S) {
        int ans = INT_MAX;
        for(int k=0; k <= S.size(); k++){
            int ans1 = 0, ans2 = 0;
            for(int i = 0; i < k; i++)
                if(S[i] != '0') ans1++;
            for(int j = k; j < S.size(); j++)
                if(S[j] != '1') ans2++;
            ans = min(ans1 + ans2, ans);
        }
        return ans;
    }
};

class Solution2 {
    // DP version of Solution above, O(n) in time and O(n) in space;
    // create two arrays to cache the 
public:
    int minFlipsMonoIncr(string S) {
        vector<int> left(S.size()+1, 0);
        vector<int> right(S.size()+1, 0);
        for(int i = 0; i < S.size(); i++) {
            left[i+1] += left[i];
            if(S[i] != '0') left[i+1]++;
        }
        for(int j = S.size()-1; j>=0; j--) {
            right[j] += right[j+1];
            if(S[j] != '1') right[j]++;
        }

        int ans = left[0] + right[0];
        for(int k = 1; k <= S.size(); k++)
            ans = min(ans, left[k] + right[k]);
        return ans;
    }
};