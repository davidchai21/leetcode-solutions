class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one=INT_MAX;
        int two=INT_MAX;
        for (int a:nums) {
            if (a<=one) one=a;
            else if (a<=two) two=a;
            else return true;
        }
        return false;
    }
};