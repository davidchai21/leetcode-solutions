class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        for (int i : x) {
            f = e; e = d; d = c; c = b; b = a; a = i;
            if (d >= b && b > 0 && (a >= c || (c - e) <= a && c >= e && (d - f) <= b))
            return true;
        }
    return false;
    }
};