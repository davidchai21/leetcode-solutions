class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t<0 || k<1 || nums.size()<2) return false;
        unordered_map<long long, long long> m;
        long long w=t+1;
        for (int i=0;i<nums.size();i++) {
            long long index=getbucket(nums[i],w);
            if (m.find(index)!=m.end()) return true;
            if (m.find(index-1)!=m.end() && nums[i]-m[index-1]<=t || m.find(index+1)!=m.end() && m[index+1]-nums[i]<=t) return true;
            if (i>=k) m.erase(getbucket(nums[i-k],w));
            m[index]=(long long)nums[i];
        }
        return false;
    }
    inline long long getbucket(long long t, long long w) {
        return t<0? (t+1)/w-1:t/w;
    }
};