class Solution {
public:
    bool canPermutePalindrome(string s) {
        for (char t:s) m[t]++;
        int sum=0;
        for (auto& t:m)
        {
            if (t.second%2) sum++;
        }
        return sum<=1;
    }
private:
    unordered_map<char,int> m;
};