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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        vector<int> prefixSum(words.size() + 1, 0);
        for(int i = 0; i < words.size(); ++i) 
        	prefixSum[i + 1] = prefixSum[i] + 
        		(vowels.count(words[i].back()) && vowels.count(words[i].front()));

        vector<int> answers;
        for(vector<int>& range : queries) {
        	answers.push_back(prefixSum[range[1] + 1] - prefixSum[range[0]]);
        }
        return answers;
    }
};