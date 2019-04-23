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
    /* Using Stack and sorting.
     * Two ordered Intervals can be merged: [l1, r1], [l2, r2].
     *      1. l1 <= l2
     *      2. no limitation on r1 and r2 
     *      3. there will be overlapping when l2 < r1
     */
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> vec;
        sort(intervals.begin(), intervals.end(), [](Interval &lhs, Interval &rhs) {return lhs.start < rhs.start;});

        for(Interval interval : intervals) {
            if(vec.empty() || interval.start > vec.back().end) 
                vec.push_back(interval);
            else
                vec.back().end = max(interval.end, vec.back().end);
        }
        return vec;
    }
};