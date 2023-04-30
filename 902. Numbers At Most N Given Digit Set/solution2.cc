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

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/


class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
    	// Recursive
    	// digits vs num [i]
    	// assume number n is of size l, we can freely use digits to form numbers of size < l
    	// 
    	// Pattern
    	// ways(num,i) = ways(num, i+1) + # free positioning
    	// free positioning = (# of val < num[i]) * (digits.size() ^ (n-i-1))
    	vector<string> num;
    	for(char c : to_string(n)) 
    		num.push_back(string() + c);
    	size = num.size();

    	// precompute the # of numbers of size < l
    	numbers = vector<long>(size, 0);
    	numbers[0] = 1;
    	for(int i = 1; i <= size - 1; ++i)
    		numbers[i] = numbers[i-1] * digits.size();

    	long sum = accumulate(numbers.begin() + 1, numbers.end(), 0l);
    	return ways(digits, num, 0) + sum;
    }
private:
	int size = 0;
	vector<long> numbers;
	int ways(vector<string>& digits, vector<string>& num, int i) {
		if(i == num.size()) {
			return 1;
		}
		int j = lower_bound(digits.begin(), digits.end(), num[i]) - digits.begin();

		long base = j;
		if(j > 0) {
			base *= numbers[num.size() - i - 1];
		}

		if(j == digits.size() || digits[j] > num[i])
			return base;
		else 
			return base + ways(digits, num, i + 1);
	}
};