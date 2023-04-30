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

using namespace std;

class UnionFind {
public:
  UnionFind(int n) {
    ranks_ = vector<int>(n+1, 0);
    parents_ = vector<int>(n+1, 0);

    for(int i = 0; i < n; ++i)
      parents_[i] = i; // initialize each to itself
  }
  int Find(int u) {
    if(u != parents_[u])
      parents_[u] = Find(parents_[u]);
    return parents_[u];
  }
  bool Union(int u, int v) { // can union?
    int pu = Find(u);
    int pv = Find(v);

    if(pu == pv) return false;

    if(ranks_[pv] > ranks_[pu])
      parents_[pu] = pv;
    else if(ranks_[pv] < ranks_[pu])
      parents_[pv] = pu;
    else {
      parents_[pv] = pu;
      ranks_[pu] += 1;
    }
    return true;
  }
  
private:
  vector<int> ranks_;
  vector<int> parents_;
};


class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
    	int n = strs.size();
    	UnionFind uf(n);
    	for(int i = 0; i < strs.size(); ++i) {
    		for(int j = i + 1; j < strs.size(); ++j) {
    			if(isSimilar(strs[i], strs[j]))
    				uf.Union(i, j);
    		}
    	}
    	unordered_set<int> s;
    	for(int i = 0; i < n; ++i)
    		s.insert(uf.Find(i));
    	return s.size();
    }
private:
	bool isSimilar(string& w1, string& w2) {
		string w1cp = w1;
		int i = -1, j = -1, cnt = 0;

		for(int k = 0; k < w1.size(); ++k) {
			if(w1[k] == w2[k]) continue;
			else {
				cnt++;
				if(i == -1) i = k;
				else if(j == -1) j = k;
			}
		}
		if(cnt > 2) return false;
        else if(cnt == 0) return true;
		return w1[j] == w2[i] && w1[i] == w2[j];
	}
};