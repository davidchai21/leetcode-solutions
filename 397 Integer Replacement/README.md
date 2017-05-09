This question is not hard. We can write a iterative function to find the solution. However, there is another smarter way to solve it.

We can look at the binary representation of the current number. If it has 2 zeros, we just do the division. If it has 2 ones, we add it one to make it 2 zeros. If it has one 1 and one 0, we can either do add or deduction.

Runtime: 6ms
