class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int t=b.back();
        b.pop_back();
        return helper(superPow(a,b),10)*helper(a,t)%base;
    }
private:
    const int base=1337;
    int helper(int a, int n)
    {
        a%=base;
        int res=1;
        for (int i=0;i<n;i++)
        {
            res=(res*a)%base;
        }
        return res;
    }
};