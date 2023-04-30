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
    int getMinSwaps(string num, int k) {
   		string numcopy = num;
   		while(k--)
   			getNextPermutation(numcopy);
   		int res = 0;
   		for(int i = 0; i < num.size(); ++i) {
   			if(num[i] == numcopy[i]) continue;
   			int j = i + 1;
   			while(num[j] != numcopy[i])
   				j++;
   			for(; j > i; --j)
   				swap(num[j], num[j - 1]), res++;
   		}
   		return res;
    }
private:
	void getNextPermutation(string& num) {
		int n = num.size();
		int k = n - 2;
		while(k >= 0 && num[k] >= num[k+1]) 
			--k;
		int l = n - 1;
		while(l > k && num[k] >= num[l])
			--l;
		swap(num[k], num[l]);
		reverse(num.begin() + k + 1, num.end());
	}
};