#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
    // quick select O(n)
    // O(n^2) worst
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int pos = partition(nums, l, r);
            if(pos + 1 == k) return nums[pos];
            else if(pos + 1 < k) l = pos+1;
            else r = pos-1;
        }
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left;
        int r = right;
        while(l <= r) {
            if(nums[l] < pivot && nums[r] >= pivot) 
                swap(nums[l++], nums[r--]);
            if(nums[l] >= pivot) l++;
            if(nums[r] < pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};


class Solution2 {
    // Priority queue - Heap - O(nlogk)
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < nums.size(); i++){
            int p = nums[i];
            if(q.size() < k) q.push(p);
            else if(q.top() < p) {
                q.pop();
                q.push(p);
            }
        }
        return q.top();
    }
};