This question is kind of trivial. We need pick every sample from the string vector. For each string type, we collect all the strings suit and store them in the sub-vector. Then, at last we return the vector of vectors.

The reason I chose to use multiset is because it can save duplicates.

Rumtime: 55ms
