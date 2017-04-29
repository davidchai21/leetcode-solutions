This question is easy. We can find the minimum by traversing the whole string and return when the next one is larger than current one.

Another case which is faster is to use the binary search. Just narrow the 2 pointers to find the correct number.

However, the test cases show that 2 methods used the same time.

Runtime: 3ms
