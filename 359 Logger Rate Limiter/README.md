This question is not hard. Some people used map, it's ok since map can solve it easily. But I don't think so, like map will store every sentence appeared in the past. If there are tons of different values, then it's not good for the system.

Rather, using a deque is a good choice. We can set a time window to record the messages in the last 10 seconds.

Runtime: 72ms
