class Solution {
public:
    int maxA(int N) {
        if (N<7) return N;
        return max(max(maxA(N-3)*2,maxA(N-4)*3),maxA(N-5)*4);
    }
};