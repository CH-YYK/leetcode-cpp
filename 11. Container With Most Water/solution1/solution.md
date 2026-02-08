Intuitively, the solution is to compare every result formed by any pair of `[i,j]`.

```
area = Min(height_i, height_j) * (j - i)
```

Since the area is defined by the smaller one between the (height_i and height_j), we update the one which is smaller.

### Why the two-pointer approach works

We start with the widest possible container, using pointers at both ends of the array (`left` and `right`).

The area is calculated as `area = min(height[left], height[right]) * (right - left)`. The area is limited by the shorter of the two lines and the distance between them.

When we move a pointer, the width `(right - left)` is guaranteed to decrease. To find a larger area, we need a height that is significantly larger to compensate for the smaller width.

Let's assume `height[left] < height[right]`:
- The current area is limited by `height[left]`.
- If we move the `right` pointer inwards, the new width `(new_right - left)` will be smaller. The new area will be `min(height[left], height[new_right]) * (new_right - left)`. Since `min(height[left], height[new_right])` cannot be greater than `height[left]`, the new area is guaranteed to be **smaller** than or equal to the current area.
- If we move the `left` pointer inwards, we are hoping to find a `height[new_left]` that is taller. While the width is smaller, a much taller `new_left` line could potentially create a larger area with the `right` line.

So, at each step, we eliminate the shorter line because it cannot be part of a larger container with any other line between the current pointers. We move the pointer of the shorter line inwards, continuing our search for a better container, while keeping the taller line because it has more potential. This guarantees that we do not miss the optimal solution.