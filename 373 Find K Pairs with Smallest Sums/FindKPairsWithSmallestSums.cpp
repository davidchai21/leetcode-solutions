class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        
        for (int i=0;i<nums1.size();i++)
        {
            for (int j=0;j<nums2.size();j++)
            {
                res.push_back(make_pair(nums1[i],nums2[j]));
            }
        }
        sort(res.begin(),res.end(),[](pair<int,int> a,pair<int,int> b){return (a.first+a.second<b.first+b.second);});
        vector<pair<int,int>> t(res.begin(),res.begin()+(k>res.size()?res.size():k));
        return t;
    }
};