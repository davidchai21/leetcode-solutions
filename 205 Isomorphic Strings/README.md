This question is easy. We just need to build tables to store and look at. If there is conflictions, we return false; otherwise, return true.

One thing to notice is that the comparison is double-sided, so we have to build 2 tables. e.g. s="ab", t="aa", we should return false.

Runtime: 6ms
