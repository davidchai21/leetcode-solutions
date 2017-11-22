class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i=left;i<=right;i++) {
            if (check(i)) res.push_back(i);
        }
        return res;
    }
    bool check(int n) {
        int t=n;
        while (t) {
            int r=t%10;
            if (r==0 || n%r) return false;
            t/=10;
        }
        return true;
    }
};