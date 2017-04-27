This question is not that hard, but we have to consider every possible case in this problem. That's the point.

We can divide the whole string into 3 partitions, the first and last are checking numbers, the middle is scientific symbol 'e'. If one of the three returns false, then return false. Only when they all match, we return true. Don't forget about the dot '.' and blanks in the string.

Runtime: 9ms
