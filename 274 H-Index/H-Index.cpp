class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> t(n+1,0);
        for (int i=0;i<n;i++) {
            if (citations[i]>=n) t[n]++;
            else t[citations[i]]++;
        }
        int sum=0;
        for (int i=n;i>=0;i--) {
            sum+=t[i];
            if (sum>=i) return i;
        }
        return 0;
    }
};