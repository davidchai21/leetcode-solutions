This question is easy. Use a hashmap to do so and a vector to save the values.

When deleting, do the swap with the last item in the vector and pop_back(). Don't forget to update the index in the map.

Runtime: 52ms
