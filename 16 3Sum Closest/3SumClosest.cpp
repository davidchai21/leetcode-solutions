class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //int res=INT_MAX;
        int n=nums.size();
        if (n<3) return INT_MIN;
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        for (int i=0;i<n-2;i++)
        {
            int front=i+1;
            int back=n-1;
            while (front<back)
            {
                int k=nums[i]+nums[front]+nums[back];
                if (k<target)
                {
                    if (abs(res-target)>abs(k-target)) res=k;
                    front++;
                }
                else if (k>target)
                {
                    if (abs(res-target)>abs(k-target)) res=k;
                    back--;
                }
                else return target;
            }
        }
        return res;
    }
};