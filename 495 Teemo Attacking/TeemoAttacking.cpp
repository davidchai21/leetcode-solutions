class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (duration<=0) return 0;
        int res=0;
        int n=timeSeries.size();
        int i=0;
        while (i<n)
        {
            int j=i+1;
            if (j<n){
                if (timeSeries[j]<=timeSeries[i]+duration)
                {res+=timeSeries[j]-timeSeries[i];}
                else res+=duration;
            }
            else res+=duration;
            i=j;
        }
        return res;
    }
};