class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int record=0;
        int res=0;
        for (int i=0;i<9;i++) res+=helper(i,record,1,m,n);
        return res;
    }
    int helper(int to, int& record, int len, int m, int n) {
        if (len>=n) return 1;
        record|=(1<<to);
        int s=0;
        for (int i=0;i<9;i++) {
            if (valid(to,i,record)) {
                s+=helper(i,record,len+1,m,n);
            }
        }
        record&=~(1<<to);
        if (len>=m) s++;
        return s;
    }
    bool valid(int from, int to, int record) {
        if (visited(to,record)) return false;
        int x=from/3+to/3;
        int y=from%3+to%3;
        if (record==0 || x%2 || y%2) return true;
        int mid=(from+to)/2;
        if (visited(mid,record)) return true;
        return false;
    }
    bool visited(int m, int record) {
        return record&(1<<m);
    }
};