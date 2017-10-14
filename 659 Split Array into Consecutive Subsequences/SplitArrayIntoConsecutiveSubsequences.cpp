class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count, tail;
        for (int a:nums) count[a]++;
        for (int a:nums) {
            if (count[a]==0) continue;
            count[a]--;
            if (tail[a-1]) {
                tail[a-1]--;
                tail[a]++;
            }
            else if (count[a+1] && count[a+2]) {
                count[a+1]--;
                count[a+2]--;
                tail[a+2]++;
            }
            else return false;
        }
        return true;
    }
};