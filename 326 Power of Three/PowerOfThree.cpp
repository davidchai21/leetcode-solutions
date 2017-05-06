class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<1) return false;
        return (m%n==0);
    }
private:
    int const m=1162261467;
};