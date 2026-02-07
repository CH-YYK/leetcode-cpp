## Question
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

* Every element less than pivot appears before every element greater than pivot.
* Every element equal to pivot appears in between the elements less than and greater than pivot.

The **relative order** of the elements less than pivot and the elements greater than pivot is maintained.

More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.


## Analysis
On top of my mind, we can prepare two empty arrays to respectively store elements less than `pivot` and greater than `pivot`.

To avoid unnecessary collections, `ArrayList`, I'll pre-segment the result array by the numbers of each set: `less`, `equal`, `greater`, and positionally place the numbers there.



