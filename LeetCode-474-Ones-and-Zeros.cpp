#include <vector>
#include <string>
#include <tuple>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution { // recursive solution O(2^N), O(1)
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return helper(strs, m, n, 0);
    }

    int helper(vector<string> &strs, int m, int n, int i){
        if(i == strs.size() || (m <= 0 && n <= 0)) return 0;
        int m0, n1;
        tie(n1, m0) = computeOneZero(strs[i]);
        if(m - m0 >= 0 && n-n1 >= 0){
            return max(helper(strs, m-m0, n-n1, i+1) + 1, helper(strs, m,n,i+1));
        }else{
            return helper(strs, m, n, i+1);
        }
    }

    tuple<int, int> computeOneZero(string &str){
        int sum_0 = 0, sum_1 = 0;
        for_each(str.begin(), str.end(), [&](char x){x == '1' ? sum_1++ : sum_0++;});
        return make_tuple(sum_1, sum_0);
    }
};


class Solution2 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return helper(strs, m, n, 0, memo);
    }

    int helper(vector<string>& strs, int m, int n, int i, 
        vector<vector<vector<int>>>& memo) {
        if(i == strs.size() || (m <= 0 && n <= 0)) return 0;
        if(memo[i][m][n] >= 0) return memo[i][m][n];
        int m0, n1;
        tie(n1, m0) = computeOneZero(strs[i]);
        if(m-m0 >= 0 && n-n1 >= 0) {
            memo[i][m][n] = max(helper(strs, m-m0, n-n1, i+1, memo)+1, 
                                helper(strs, m, n, i + 1, memo));
        }else{
            memo[i][m][n] = helper(strs, m, n, i+1, memo);
        }
        return memo[i][m][n];
    }

    tuple<int, int> computeOneZero(string& str) {
        int sum_0=0, sum_1=0;
        for_each(str.begin(), str.end(), [&sum_0, &sum_1](char x){
            x == '1' ? sum_1++ : sum_0++;
        });
        return make_tuple(sum_1, sum_0);
    }
};

class Solution3 {
    // bottom-up solution with O(mnN) in time and O(mn) in space
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        int num_0, num_1;
    
        for(string &str : strs){
            num_0 = 0; num_1 = 0;
            for_each(str.begin(), str.end(), [&](char x){x=='1' ? num_1++ : num_0++;});
            for(int i = m; i >= num_0; i--){
                for(int j = n; j>= num_1; j--){
                    memo[i][j] = max(memo[i][j], memo[i-num_0][j-num_1] + 1);
                }
            }
        }
        return memo[m][n];
    }
};


int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    int ans = Solution3().findMaxForm(strs, m, n);
    cout << ans << "\n";
    return 0;
}