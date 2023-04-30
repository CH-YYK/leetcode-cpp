// Hello, this is a CPP leetcode snippet.

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
	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int squareFreeSubsets(vector<int>& nums) {
        // a * b % 2 * 2 = 0
        // prime decomposition
        // dp[i][k]:= number of non square-free subsets
        // [3, 4, 4, 5]
        // 16 - 8 - 4 - 1 
        vector<int> rest;
       	long total = 0;
       	int n = nums.size();
       	vector<long> power2(n + 1, 1);
       	for(int i = 1; i <= n; ++i)
       		power2[i] = power2[i - 1] * 2;

        for(int num : nums) {
        	bool twoPrimes = false;
        	for(int p : primes) {
        		int cnt = 0;
        		while(num % p == 0) {
        			cnt++;
        			num /= p;
        		}
        		if(cnt > 1) twoPrimes = true;
        	}
        	if(!twoPrimes)
        		rest.push_back(num);
        	else
        		total = total + power2[n--];
        }

        int m = rest.size();
        vector<int> usage(31, 0);
        for(int i = 0; i < m; ++i)
        	for(int j = i + 1; j < m; ++j) {
        		for(int p : primes)
        			if(rest[i] % p || rest[j] % p)
        				continue
        			else {
        				total = total + power2[m - 2 - usage[rest[i]] - rest[j]];
        				usage[rest[i]]++;
        				usage[rest[j]]++;
        				break;
        			}
        	}
        return power2[nums.size()] - total;
    }
};