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
    bool isItPossible(string word1, string word2) {
		// set(word1).size() == set(word2).size();
		// suppose 'diff': difference in the size of distinct characters
		// 1. swapping same character is redundant
		// 2. swapping can make the diff be changed by [0,1,2]
		vector<int> freq1(26, 0),freq2(26,0);
		int num1 = 0, num2 = 0;
		for(char c1 : word1) 
			if(freq1[c1 - 'a']++ == 0)
				num1++;
		for(char c2 : word2) 
			if(freq2[c2 - 'a']++ == 0)
				num2++;

		if(num1 > num2)
			return swapAndCompare(freq2, freq1, num1 - num2);
		else
			return swapAndCompare(freq1, freq2, num2 - num1);
    }
private:
	bool swapAndCompare(vector<int>& freq1, vector<int>& freq2, int diff) {
		// assume word1 has less distinct chars than word2
        if(diff > 2) return false;
		int origindiff = diff;
		for(int i = 0; i < 26; ++i)
			for(int j = 0; j < 26; ++j) {
				// freq1[i]--,freq2[i]++,freq1[j]++,freq2[j]--
				if(freq1[i] == 0) continue;
				if(freq2[j] == 0) continue;
				int a = freq1[i], b = freq2[i], c = freq1[j], d = freq2[j];
				if(--freq1[i] == 0) diff++;
				if(freq2[i]++ == 0) diff++;
				if(freq1[j]++ == 0) diff--;
				if(--freq2[j] == 0) diff--;

				if(diff == 0) return true;
				diff = origindiff;
				freq1[i] = a, freq1[j] = c;
				freq2[i] = b, freq2[j] = d;
			}
		return false;
	}
};