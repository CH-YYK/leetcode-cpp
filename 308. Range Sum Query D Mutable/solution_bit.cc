#include <vector>
using namespace std;

class FenwickTree {
public:
  FenwickTree(int n) : sums_(n+1, 0) {}
  void update(int i, int delta) {
    while(i < sums_.size()) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }
  int query(int i) {
    int sum = 0;
    while(i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }
private:
  vector<int> sums_;
  static inline int lowbit(int x) {
    return x & (-x);
  }
};

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &matrix) : matrix_(matrix) {  // O(MlogN)
    m = matrix.size();
    n = matrix[0].size();
    trees = vector<FenwickTree>(n, FenwickTree(m));
    for(int c = 0; c < n; ++c) 
        for(int r = 0; r < m; ++r)
            trees[c].update(r+1, matrix[r][c]);
  }

  void update(int row, int col, int val) {
    int delta = val - matrix_[row][col];
    matrix_[row][col] = val;
    trees[col].update(row + 1, delta);
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for(int c = col1; c <= col2; ++c){
      sum += trees[c].query(row2+1) - trees[c].query(row1);
    }
    return sum;
  }
private:
  int m, n;
  vector<FenwickTree> trees;
  vector<vector<int>>& matrix_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
