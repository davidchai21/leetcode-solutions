class Solution {
public:
    int findDerangement(int n) {
        if (n==1) return 0;
        if (n==2) return 1;
        int k=2;
        unsigned long long prepre=0;
        unsigned long long pre=1;
        unsigned long long cur=0;
        while (k<n) {
            cur=((prepre+pre)*k++)%M;
            prepre=pre;
            pre=cur;
        }
        return (int)cur;
    }
private:
    const int M=1000000007;
};