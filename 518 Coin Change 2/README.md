This question is a basic question on Dynamic Programming. It asks the total cases of coins combination. So we can define a vector to store all the values <= amount, and then pick the amount-th element to return.

One thing to notice is the input amount and coin vector size. It they are zero, we need to return 1 or 0, respectively.

Runtime: 3ms
