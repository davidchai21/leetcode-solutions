class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger>=desiredTotal) return true;
        if (maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal) return false;
        return helper(maxChoosableInteger,desiredTotal,0);
    }
    bool helper(int n, int total, int bits) {
        if (total<=0) return false;
        if (win.find(bits)!=win.end()) return true;
        if (lose.find(bits)!=lose.end()) return false;
        for (int i=n;i>0;i--) {
            int bit=1<<i;
            if (bit&bits) continue;
            if (!helper(n,total-i,bits|bit)) {
                win.insert(bits);
                return true;
            }
        }
        lose.insert(bits);
        return false;
    }
private:
    unordered_set<int> win,lose;
};