#include <vector>
#include <memory>

using namespace std;

struct SegmentTreeNode {
  int start, end, sum;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
  SegmentTreeNode(int start, int end, int sum)
    : start(start),
      end(end),
      sum(sum),
      left(nullptr), right(nullptr) {}
  ~SegmentTreeNode() {
    delete left;
    delete right;
  }
};

class SegmentTree {
  // SegmentTree for sum
public:
  SegmentTree() : root(new SegmentTreeNode(0, 0, 0)) {}
  void buildTree(vector<int>& vals) {
    SegmentTreeNode* p = root.get();
    build(p, vals, 0, vals.size() - 1);
  }
  void updateTree(int index, int val) {
    SegmentTreeNode* p = root.get();
    update(p, index, val);
  }

  int queryRange(int i, int j) {
    SegmentTreeNode* p = root.get();
    return querySum(p, i, j);
  }
private:
  unique_ptr<SegmentTreeNode> root;
  void build(SegmentTreeNode* root, vector<int> &vals, int start, int end) {
    if(start > end)
      return;
    root->start = start, root->end = end;
    if(start == end) {
      root->sum = vals[start];
      return ;
    }
    int mid = (start + end) / 2;
    root->left = new SegmentTreeNode(start, mid, 0);
    root->right = new SegmentTreeNode(mid + 1, end, 0);
    build(root->left, vals, start, mid);
    build(root->right, vals, mid + 1, end);
    root->sum = root->left->sum + root->right->sum;
  }
  void update(SegmentTreeNode *root, int index, int val) {
    if (root->start == root->end && root->start == index) {
      root->sum = val;
      return;
    }
    int mid = (root->start + root->end) / 2;
    if (index <= mid) // update left/right branch
      update(root->left, index, val);
    else
      update(root->right, index, val);
    root->sum = root->left->sum + root->right->sum; // update current sum
  }
  int querySum(SegmentTreeNode *root, int i, int j) {
    if (root->start == i && root->end == j)
      return root->sum;
    int mid = (root->start + root->end) / 2;
    if (j <= mid)
      return querySum(root->left, i, j);
    else if (i > mid)
      return querySum(root->right, i, j);
    else
      return querySum(root ->left, i, mid) + querySum(root->right, mid + 1, j);
  }
};


class NumArray {
public:
  NumArray(vector<int> &nums) : tree(new SegmentTree()){
    tree->buildTree(nums);
  }

  void update(int index, int val) {
    tree->updateTree(index, val);
  }

  int sumRange(int left, int right) {
    return tree->queryRange(left, right);
  }
private:
  unique_ptr<SegmentTree> tree;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
