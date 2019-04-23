#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    /* Insert the new interval to `intervals`, then merge them one by one
     *      O(N) time and easy to understand.
     *      cons: in worst case, we have to copy the whole list
     */
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end() && it->start < newInterval.start){ 
            it++;
        }
        intervals.insert(it, newInterval);

        vector<Interval> ans;
        for(auto interval : intervals) {
            if(ans.empty() || ans.back().end < interval.start)
                ans.push_back(interval);
            else
                ans.back().end = max(ans.back().end, interval.end);
        }
        return ans;
    }
};

class Solution {
    /* partition intervals to three subsets: left, middle, right
     *      where middle are intervals that have overlappings to the `newInterval`
     * 
     */
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> left;
        vector<Interval> right;
        int start = newInterval.start, end = newInterval.end;

        for(Interval interval : intervals) {
            if(interval.end < start) left.push_back(interval);
            else if(interval.start > end) right.push_back(interval);
            else {
                start = min(start, interval.start);
                end = max(end, interval.end);
            }
        }

        vector<Interval> ans(std::move(left));
        ans.emplace_back(start, end);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};