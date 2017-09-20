class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size()<2) return 0;
        map<int,int> m;
        for (int i:nums) m[i]++;
        int res=0;
        int pre=0;
        int precount=0;
        for (pair<int,int> p:m)
        {
            if (precount && pre+1==p.first)
            {
                res=max(res,precount+p.second);
            }
            pre=p.first;
            precount=p.second;
        }
        return res;
    }
};