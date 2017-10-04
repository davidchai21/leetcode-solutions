class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0;
        for (int a:nums) {
            one=(one^a)&~two;
            two=(two^a)&~one;
        }
        return one;
    }
};