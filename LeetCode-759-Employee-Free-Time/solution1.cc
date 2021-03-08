struct cmp_interval {
  bool operator()(Interval& lhs, Interval& rhs) {
    return lhs.start > rhs.start;
  }
};

class Solution {
public:
  /* Get the finite itervals representing common positive length free-time
   *  - Sort intervals on the time range
   *  - union of work time , U
   *  - complement to U, and get rid of infinite-length interval
   *  -> take O(NlogN) , N,number of intervals in total.
   *
   * -> similar to "Merge K sorted lists"
   */
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

    int cnt = 0, n = schedule.size();
    Interval tmp;
    priority_queue<Interval, vector<Interval>, cmp_interval> _q;
    for(int i = 0; i < n; ++i)
      for(Interval& interval : schedule[i])
        _q.push(interval), ++cnt;

    vector<Interval> res;

    int end = 0;
    while(!_q.empty()) {
      tmp = _q.top();
      _q.pop();

      if(end == 0) end = tmp.end;
      else {
        if(end < tmp.start)
          res.emplace_back(end, tmp.start);
        else
          end = max(tmp.end, end);
      }
    }
    return res;
  }
};
