class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a;
        a=accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        a&=-a;
        vector<int> res={0,0};
        for (int i:nums)
        {
            if ((i&a)==0)
            {
                res[0]^=i;
            }
            else
            {
                res[1]^=i;
            }
        }
        return res;
    }
};