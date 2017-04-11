This question is kind of easy. One way to solve it is to divide the whole range into several parts, and the next part's 1s is larger than the previous. So we can add them one by one.

Another way is to use bit manipulation, we just use n&(n-1) to eliminate the rightmost 1 and plus 1 with the number of the number.

Runtime: 39ms
