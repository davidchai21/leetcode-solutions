class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n=nums.size();
        vector<string> res(n,"");
        vector<pair<int,int> > a;
        for (int i=0;i<n;i++)
        {
            a.push_back(make_pair(nums[i],i));
        }
        sort(a.begin(),a.end(),[](pair<int,int> a, pair<int,int> b){return a.first>b.first;});
        for (int i=0;i<n;i++)
        {
            if (i>2) res[a[i].second]=to_string(i+1);
            else if (i==0) res[a[i].second]="Gold Medal";
            else if (i==1) res[a[i].second]="Silver Medal";
            else res[a[i].second]="Bronze Medal";
        }
        return res;
    }
};