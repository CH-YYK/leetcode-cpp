bool cmp(vector<int>& lhs, vector<int>& rhs) {
    if(lhs[0] < rhs[0]) return true;
    else return lhs[1] < rhs[1];
};

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int res = 0;

    sort(intervals.begin(), intervals.end(), cmp);
    vector<int>& last = intervals[0];
    for(int i = 1; i < intervals.size(); ++i) {
      if(!is_overlap(last, intervals[i])) last = intervals[i];
      else {
        // keep the one that generate shorter distance to right, which is safer
        if(last[1] > intervals[i][1]) last = intervals[i];  
        res++;
      }
    }
    return res;
  }
 private:
  /** Check if lhs overlapped with rhs
   */
  bool is_overlap(vector<int>& lhs, vector<int>& rhs) {
    return lhs[1] > rhs[0];  
  }
};