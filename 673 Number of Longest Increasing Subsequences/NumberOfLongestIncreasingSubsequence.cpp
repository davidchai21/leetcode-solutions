class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n<2) return n;
        int l=0;
        int res=0;
        vector<pair<int,int> > s(n,{0,0}); // largest queue size, number of queues
        s[0]={1,1};
        for (int i=1;i<n;i++) {
            for (int j=i-1;j>=0;j--) {
                if (nums[i]>nums[j]) s[i].first=max(s[i].first,s[j].first+1);
            }
            if (s[i].first==0) s[i]={1,1};
            for (int j=0;j<i;j++) {
                if (nums[i]>nums[j] && s[i].first==s[j].first+1) s[i].second+=s[j].second;
            }
            l=max(l,s[i].first);
        }
        for (int i=0;i<n;i++) {
            if (s[i].first==l) res+=s[i].second;
        }
        return res;
    }
};