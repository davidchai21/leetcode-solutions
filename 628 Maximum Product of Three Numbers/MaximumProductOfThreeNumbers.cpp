class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int l1=1000;
        int l2=1000;
        int r1=-1000;
        int r2=-1000;
        int r3=-1000;
        for (int a:nums)
        {
            if (a<l1)
            {
                l2=l1;
                l1=a;
            }
            else if (a>=l1 && a<l2) {l2=a;}
            if (a>r1)
            {
                r3=r2;
                r2=r1;
                r1=a;
            }
            else if (a<=r1 && a>r2)
            {
                r3=r2;
                r2=a;
            }
            else if (a<=r2 && a>r3) {r3=a;}
        }
        return max(l1*l2*r1,r1*r2*r3);
    }
};