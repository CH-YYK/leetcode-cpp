The array is already sorted by value. 

Given an array (`nums`), position index `i` and `j`, there could be
* `nums[i] <= nums[j] <= 0` and `abs(nums[i]) >= abs(nums[j])`.
* `0 <= nums[i] <= nums[j]` and `abs(nums[i]) <= abs(nums[j])`.
* `nums[i] <= 0 <= nums[j]` both above can happen.

Suppose `nums[z] == 0`, the array can thus be splitted into two non-decreasing subarrays, and the problem is thus reduced to **merge** two sorted arrays.

There indeed that 0 might not be in the array, so we can stop at the value that is right smaller than 0.