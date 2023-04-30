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

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int _min = INT_MAX;
        int _max = INT_MIN;
        double sum = 0;
        for(int num : salary) {
            _min = min(_min, num);
            _max = max(_max, num);
            sum += num;
        }
        return (sum - _min - _max) / (salary.size() - 2);
    }
};
