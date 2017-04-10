class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int res=0;
        int range=minutesToTest/minutesToDie+1;
        while (pow(range,res)<buckets) res++;
        return res;
    }
};