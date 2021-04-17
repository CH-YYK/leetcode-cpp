#include <vector>
#include <memory>
using namespace std;

struct BSTNode{
  int cnt;
  int val;
  int numless;
  BSTNode* left, *right;
  BSTNode(int value) : cnt(1), val(value),
                       numless(0),
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
  BST(int first) : root(new BSTNode(first)) {} 
  void insert(int num) {
    BSTNode* p = root.get();
    BSTNode* node = new BSTNode(num);

    while(p != node) {
      if(num > p->val) {  // num > p->val
        node->numless += p->cnt + p->numless;
        if(!p->right) 
          p->right = node;
        p = p->right;
      } else if (num == p->val) { // num == p->val
        p->cnt++;
        break;
      } else {  // num < p->val
        p->numless++;
        if(!p->left) 
          p->left = node;
        p = p->left;
      }
    }
  }
  int search(int num) {
    int numless = 0;
    BSTNode* p = root.get();
    while(p) {
      if(num > p->val) {
        numless = p->cnt + p->numless;
        p = p->right;
      } else if(num < p->val) {
        p = p->left;
      } else {
        numless = p->cnt + p->numless;
        break;
      }
    }
    return numless;  // number of values that are <= num;
  }
private:
  unique_ptr<BSTNode> root;
};


class Solution {
public:
  int reversePairs(vector<int> &nums) {
    BST bst(nums[0]);
    int bstsize = 1;
    int res = 0;
    for(int i = 1; i < nums.size(); ++i){
      int tmp = bst.search(2 * nums[i]);
      res += bstsize - tmp;
      bst.insert(nums[i]);
    }
    return res;
  }
};
