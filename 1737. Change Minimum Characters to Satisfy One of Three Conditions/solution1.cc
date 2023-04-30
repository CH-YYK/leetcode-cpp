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
    int minCharacters(string a, string b) {
    	int minChange = INT_MAX;
    	// find a line to make a all greater and b smaller
		vector<int> freqA(26, 0), freqB(26, 0);
		for(char c : a)
			freqA[c - 'a']++;
		for(char c : b)
			freqB[c - 'a']++;
		// condition 1 and condition 2
		minChange = min(minChange, makeAGreaterThanB(freqA, freqB, a.size(), b.size()));
		// condition 3
		minChange = min(minChange, makeOneDistinctChar(freqA, freqB));
		return minChange;
    }
private:
	int makeAGreaterThanB(vector<int>& freqA, vector<int>& freqB, int aSize, int bSize) {
		// find the line to increase a and line-1 to decrease b
		int minChange = INT_MAX;
		int changeA = 0, changeB = 0;
		for(int c = 1; c <= 25; ++c) {
			changeA += freqA[c - 1];
			changeB += freqB[c - 1];
			minChange = min(minChange, changeA + bSize - changeB);
			minChange = min(minChange, changeB + aSize - changeA);
		}
		return minChange;
	}

	int makeOneDistinctChar(vector<int>& freqA, vector<int>& freqB) {
		int maxCount = 0, sum = 0;
		for(int i = 0; i < 26; ++i) {
			sum += freqA[i] + freqB[i];
			maxCount = max(freqA[i] + freqB[i], maxCount);
		}
		return sum - maxCount;
	}
};