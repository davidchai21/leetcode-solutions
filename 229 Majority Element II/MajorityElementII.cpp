class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=0;
        int b=1;
        int n1=0;
        int n2=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==a) n1++;
            else if (nums[i]==b) n2++;
            else if (n1==0) {
                a=nums[i];
                n1=1;
            }
            else if (n2==0) {
                b=nums[i];
                n2=1;
            }
            else {
                n1--;
                n2--;
            }
        }
        vector<int> res;
        if (count(nums.begin(),nums.end(),a)>nums.size()/3) res.push_back(a);
        if (count(nums.begin(),nums.end(),b)>nums.size()/3) res.push_back(b);
        return res;
    }
};