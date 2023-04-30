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
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
    	unordered_set<string> good;
    	unordered_set<string> bad;
    	for(string& str : positive_feedback)
    		good.insert(str);
    	for(string& str : negative_feedback)
    		bad.insert(str);

    	priority_queue<pair<int,int>> pq; // maxheap <points, -id>
    	int n = student_id.size();
    	for(int i = 0; i < n; ++i) {
    		int points = 0;
    		stringstream ss(report[i]);
    		string word;
    		while(ss >> word) {
    			if(good.count(word))
    				points += 3;
    			else if(bad.count(word))
    				points -= 1;    			
    		}
    		pq.emplace(points, -student_id[i]);
    	}
    	vector<int> res;
    	while(!pq.empty()) {
    		auto [p, nid] = pq.top();
    		pq.pop();
    		res.push_back(-nid);
            if(res.size() == k)
                return res;
    	}
    	return res;
    }
};