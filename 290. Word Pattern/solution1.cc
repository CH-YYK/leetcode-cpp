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
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        int i = 0;
        unordered_map<char, string> mp;
        unordered_map<string char> mp2;
        while(ss >> word) {
        	if(mp.count(pattern[i])){
        		if(word != mp[pattern[i]])
        			return false;
        	} else if(mp2.count(word)) {
        		if(pattern[i] != mp2[word])
        			return false;
        	} else {
        		mp[pattern[i]] = word;
        		mp2[word] = pattern[i];
        	}
        	i++;
        }
        return i == pattern.size();
    }
};