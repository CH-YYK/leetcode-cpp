#include <memory>
#include <vector>

using namespace std;

struct SegmentTreeNode {
  int start, end, sum; // sum/min/max
  SegmentTreeNode* left, *right;
  SegmentTreeNode(int start, int end)
    : start(start), end(end), sum(0),
      left(nullptr), right(nullptr){}
  ~SegmentTreeNode() {
    delete left;
    delete right;
  }
};

class SegmentTree {
public:
  SegmentTree() : root(new SegmentTreeNode(0, 0)) {}
  void buildTree(vector<int>& vals) {
    SegmentTreeNode* p = root.get();
    build(p, vals, 0, vals.size() - 1);
  }
  void updateTree(int index, int val) {
    SegmentTreeNode* p = root.get();
    update(p, index, val);
  }
  void queryRange(int i, int j) {
    SegmentTreeNode* p = root.get();
    return query(p, i, j);
  }
private:
  unique_ptr<SegmentTreeNode> root;
  void build(SegmentTreeNode* root, vector<int>& vals, int start, int end) {
    if(start > end) return ;
    if(start == end) {
      root->sum = vals[start];
      return ;
    }
    int mid = (start + end) / 2;
    root->left = new SegmentTreeNode(start, mid);
    root->right = new SegmentTreeNode(mid+1, end);
    build(root->left, vals, start, mid);
    build(root->right, vals, mid+1, end);
    root->sum = root->left->sum + root->right->sum;
  }

  void update(SegmentTreeNode* root, int index, int val) {
    if(root->start == root->end && root->start == index) {
      root->sum = val;
      return;
    }
    int mid = (root->start + root->end) / 2;
    if(index <= mid)
      update(root->left, index, val);
    else
      update(root->right, index, val);
    root->sum = root->left->sum + root->right->sum;
  }

  int query(SegmentTreeNode* root, int i, int j) {
    if(root->start == i && root->end == j)
      return root->sum;
    int mid = root->start + (root->end - root->start) / 2;
    if(j <= mid)
      return query(root->left, i, j);
    else if(i > mid)
      return query(root->right, i, j);
    return query(root->left, i, mid) + query(root->right, mid+1, j);
  }
};
