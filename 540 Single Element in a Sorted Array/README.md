This question is straightforward. We just need to define 2 pointers pointing to either end of the array. Then we check the values and narrow the range. At last when the 2 pointers point to the same value, just return the value.

If this question doesn't require the nlogn time complexity, we can use bit manipulation to find the value --  just traverse the whole array and it's done.

Runtime: 9ms
