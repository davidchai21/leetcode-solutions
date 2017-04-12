class Solution {
public:
    int minMoves(vector<int>& nums) {
        int move=0;
        if (nums.size()==0) return 0;
        int mini=mina(nums);
        for (int i=0;i<nums.size();i++)
        {
            move+=nums[i]-mini;
        }
        return move;
    }
private:
    int mina(vector<int>& a)
    {
        if (a.size()==0) return false;
        int res=INT_MAX;
        for (int i=0;i<a.size();i++)
        {
            if (res>a[i]) res=a[i];
        }
        return res;
    }
};