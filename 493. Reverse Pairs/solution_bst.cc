#include <vector>
#include <memory>
using namespace std;

/* TLE: BST hasn't been balanced if input array is sorted
 * Complexity can be as large as O(N^2)
 */
struct BSTNode{
  int cnt;
  int val;
  int numleft;
  BSTNode* left, *right;
  BSTNode(int value) : cnt(1), val(value),
                       numleft(0),
                       left(nullptr),
                       right(nullptr) {}
  ~BSTNode() {
    delete left;
    delete right;
  }
};

class BST {
public:
  BST() : root(nullptr) {}
  BST(int first) : root(new BSTNode(first)), size(1) {}
  void insert(int num) {
    size++;
    BSTNode* p = root.get();
    BSTNode* node = new BSTNode(num);

    while(p != node) {
      if(num > p->val) {  // num > p->val
        // node->numless += p->cnt + p->numless;
        if(!p->right)
          p->right = node;
        p = p->right;
      } else if (num == p->val) { // num == p->val
        p->cnt++;
        break;
      } else {  // num < p->val
        p->numleft++;
        if(!p->left)
          p->left = node;
        p = p->left;
      }
    }
  }
  int search(long num) {
    int numless = 0;  // num of nodes in BST that are less
    BSTNode* p = root.get();
    while(p) {
      if(num > p->val) { // go right
        numless += p->cnt + p->numleft;
        p = p->right;
      } else if(num < p->val) { // go left
        p = p->left;
      } else {
        numless += p->numleft;
        break;
      }
    }
    return numless;  // number of values that are < num;
  }
private:
  unique_ptr<BSTNode> root;
  int size = 0;
};


class Solution {
public:
  int reversePairs(vector<int> &nums) {
    BST bst(-nums[0]);
    int bstsize = 1;
    int leftmax = nums[0];
    int res = 0;
    for(int i = 1; i < nums.size(); ++i){
      int tmp;
      if(nums[i] <= leftmax)  {
        tmp = bst.search(-2 * (long)nums[i]);
        res += max(tmp, 0);
      } else
        leftmax = nums[i];
      bst.insert(-1 * nums[i]);
      bstsize++;
    }
    return res;
  }
};
