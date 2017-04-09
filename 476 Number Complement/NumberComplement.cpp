class Solution {
public:
    int findComplement(int num) {
        int t=~0; // all bits are set to be 1
        while (t&num) t<<=1; // move t's bits leftward
        return (~t & ~num); // eliminate all 1's of ~num
    }
};