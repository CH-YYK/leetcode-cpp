The array contain the numbers having duplicates.

Since the array is sorted, obviously the duplicated numbers must be consecutively positioned.

Given that the changes must be applied in place,
we can thus maintain two pointers, with 
* l:= actual non duplicate results
* r:= the next non-duplicate number.

While we let `l` to keep track of the result list, `r` is scanning forward (without looking back) to find the next non-dup number.

We swap number at `l` and `r` anytime after finding a pair of valid values.
