class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n,1);
        int c=0;
        int i=1;
        int j=n;
        while (c<k) {
            if (c%2==0) res[c++]=i++;
            else res[c++]=j--;
        }
        if (k%2) {
            for (int t=i;t<=j;t++) res[c++]=t;
        }
        else {
            for (int t=j;t>=i;t--) res[c++]=t;
        }
        return res;
    }
};