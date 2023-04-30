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

using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
     	long sum = accumulate(nums.begin(), nums.end(), 0l);
        long diff = goal - sum;
     	return abs(diff) / limit + (diff % limit != 0);
    }
};