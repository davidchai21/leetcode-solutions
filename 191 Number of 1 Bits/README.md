This question is easy. One direct way is to count every bit's value and move forward until 32. Another way is even better, because n&(n-1) drops the last 1 in the number, so we just do this until n==0.

Rumtime: 3ms
