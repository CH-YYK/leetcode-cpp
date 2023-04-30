//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// To order the intervals
struct lessInterval {
    bool operator()(Interval &lhs, Interval &rhs) {
        return lhs.start < rhs.start;
    }
};