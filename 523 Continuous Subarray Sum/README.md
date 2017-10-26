The easy-to-go solution is try to find every range of sum and see if it's a multiple of k. This is very time consuming.

A smart way is to add and see if the residue appears before. If it appears, then the middle element must be qualified.

But later, LeetCode has changed the test cases, so a new and better way to do so is using a map and follow the above idea.

Runtime: 26ms->29ms
