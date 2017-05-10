class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if (n<2) return nums;
        sort(nums.begin(),nums.end());
        vector<int> l(n,0);
        vector<int> h(n,0);
        int res=0;
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (nums[i]%nums[j]==0 && l[i]<1+l[j])
                {
                    l[i]=1+l[j];
                    h[i]=j;
                }
                //if (l[i]>l[res]) {res=i;}
            }
            if (l[i]>l[res]) {res=i;}
        }
        
        vector<int> a;
        while (l[res])
        {
            a.push_back(nums[res]);
            res=h[res];
        }
        a.push_back(nums[res]);
        return a;
    }
};