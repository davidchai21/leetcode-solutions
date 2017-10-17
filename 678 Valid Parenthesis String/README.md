This question is easy. By using Greedy algorithm we can solve it linearly. 

We need to use a number to record the left parenthesis and another to record the right parenthesis. If the right count is bigger than other characters, we need to return false; update the left counter every loop to get closest to zero.

Runtime: 3ms
