This question is not that easy. The key point here is to get a clear picture of the states of everyday.

There are 3 actions one can do: buy, sell, idle at day i. Because we can only engage in only one transactions at the same time, so buy[i]=buy[i-1]. And idle means that we don't buy or sell, so idle[i]=sell[i-1]. And sell[i] is either buy[i-1]+prices[i] or sell[i-1].

Runtime: 6ms
