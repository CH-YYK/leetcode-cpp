#include "Interval.h"
#include <vector>

using namespace std;

struct lessInterval {
    bool operator()(Interval &lhs, Interval &rhs) {
        return lhs.start < rhs.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals;

        // Sorting w.r.t the start point
        sort(intervals.begin(), intervals.end(), lessInterval());

        // keep adding interval to `res`
        vector<Interval> res;
        for(Interval &interval: intervals){
            if(res.empty() || res.back().end < interval.start) {
                res.push_back(interval);
            }else if(res.back().end >= interval.start){
                res.back().start = min(res.back().start, interval.start);
                res.back().end = max(res.back().end, interval.end);
            }
        }
        return res;
    }
};