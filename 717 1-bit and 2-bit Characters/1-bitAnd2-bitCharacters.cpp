class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int count=0;
        for (int i=bits.size()-2;i>=0;i--) {
            if (bits[i]==0) break;
            else count++;
        }
        return count%2==0;
    }
};