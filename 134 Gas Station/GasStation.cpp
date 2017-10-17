class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int standard=INT_MAX;
        int n=cost.size();
        int total=0;
        int res=-1;
        for (int i=0;i<n;i++) {
            total+=gas[i]-cost[i];
            if (total<standard) {
                standard=total;
                res=i+1;
            }
        }
        return total<0?-1:res%n;
    }
};