class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A>=G || B>=H || C<=E || D<=F) return (D-B)*(C-A)+(G-E)*(H-F);
        return (D-B)*(C-A)+(G-E)*(H-F)-abs((max(A,E)-min(C,G))*(max(B,F)-min(D,H)));
    }
};