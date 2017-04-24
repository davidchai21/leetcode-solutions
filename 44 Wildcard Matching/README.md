This question is very interesting. It lets us implement the wildcard we used in Linux system.

One way to do it is by using DP. This can be correct, but the time and space used is high if the input string size is large.

Another way to do so is by using Greedy Algorithm. Just name 2 pointers and iterate the 2 strings to check the matchness. And there should be another 2 pointers marking the current scanned positions in either string.

Runtime: 45ms
