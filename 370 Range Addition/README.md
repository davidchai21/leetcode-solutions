This question is interesting. One direct way so solve it is to update every value in the array and it's done. However, this idea can be time consuming when the size of array is large.

An alternative way to do so is to record the start point of each update, as well as the end point. So that we know when to start adding and when to stop. At last, just sum the value and the previous one and it's done.

Runtime: 106ms
