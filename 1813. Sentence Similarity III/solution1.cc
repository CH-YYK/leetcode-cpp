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
    bool areSentencesSimilar(string sentence1, string sentence2) {
		// make a shorter sentence to longer
		// two sentences have common prefix and suffix 
		// the short sentence only have prefix
		stringstream ss1(sentence1), ss2(sentence2);
		vector<string> v1, v2;
		string w1, w2;
		while(ss1 >> w1)
			v1.push_back(w1);
		while(ss2 >> w2)
			v2.push_back(w2);
		return v1.size() < v2.size() ? process(v1, v2) : process(v2, v1);
    }
private:
	bool process(vector<string>& ss1, vector<string>& ss2) {
		// ss2 is longer than ss1
		int p1 = 0, p2 = 0;
		int n1 = ss1.size(), n2 = ss2.size();
		while(p1 < n1 && ss1[p1] == ss2[p2]) 
			p1++, p2++;
		int rp1 = n1 - 1, rp2 = n2 - 1;
		while(rp1 >= p1 && ss1[rp1] == ss2[rp2]) 
			rp1--, rp2--;
		return rp1 < p1;
	}
};