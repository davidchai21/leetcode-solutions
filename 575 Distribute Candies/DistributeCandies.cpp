class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        for (int i=0;i<candies.size();i++) m.insert(candies[i]);
        if (m.size()<candies.size()/2) return m.size();
        else return candies.size()/2;
    }
private:
    unordered_set<int> m;
};