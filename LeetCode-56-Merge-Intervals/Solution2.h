#include "Interval.h"
#include <vector>

using namespace std;

class Solution2 {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals;

        // Sorting w.r.t the start point
        sort(intervals.begin(), intervals.end(), lessInterval());

        // keep adding interval to `res`
        vector<Interval> res{intervals[0]};
        int i = 1;
        while(i < intervals.size()) {
            Interval *preInterval = &res.back();
            Interval curInterval = intervals[i];
            if(preInterval->end < curInterval.start) res.push_back(curInterval);
            else{
                preInterval->start = min(preInterval->start, curInterval.start);
                preInterval->end = max(preInterval->end, curInterval.end);
            }
        }
        return res;
    }
};