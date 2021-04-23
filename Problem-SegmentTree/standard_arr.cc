#include <vector>
using namespace std;

class SegmentTree {
public:
  SegmentTree() {}

  int buildTree(vector<int>& vals) {
    n = vals.size();
    nodes = vector<int>(4*n, 0);
    return build(vals, 0, vals.size() - 1, 0);
  }
  int updateTree(int index, int val){
    return update(index, val, 0, n-1, 0);
  }
  int queryTree(int i, int j) {
    return query(i, j, 0, n-1, 0);
  }
private:
  vector<int> nodes;
  int n;
  int build(vector<int>& vals, int start, int end, int idx) {
    if(start == end)
      return nodes[idx] = vals[start];
    int mid = start + (end - start) / 2;
    nodes[idx] = build(vals, start, mid, 2*idx + 1) +
      build(vals, mid+1, end, 2*idx+2);
    return nodes[idx];
  }

  int update(int index, int val, int start, int end, int idx) {
    if(start == end && start == index)
      return nodes[idx] = val;
    int mid = start + (end - start) / 2;
    if(index <= mid)
      update(index, val, start, mid, 2*idx + 1);
    else
      update(index, val, mid+1, end, 2*idx + 2);
    return nodes[idx] = nodes[2*idx+1] + nodes[2*idx+2];
  }

  int query(int i, int j, int start, int end, int idx) {
    if(start == i && end == j)
      return nodes[idx];
    int mid = start + (end - start) / 2;
    if(j <= mid)
      return query(i, j, start, mid, 2 * idx + 1);
    else if(i > mid)
      return query(i, j, mid+1, end, 2 * idx + 2);
    else
      return query(i, mid, start, mid, 2 * idx + 1) +
        query(mid+1, j, mid+1, end, 2 * idx + 2);
  }
};
