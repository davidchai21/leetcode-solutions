class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> m={{'6','9'},{'9','6'},{'0','0'},{'1','1'},{'8','8'}};
        for (int i=0, j=num.size()-1;i<=j;i++,j--)
        {
            if (m.find(num[i])!=m.end() && m[num[i]]==num[j]) continue;
            else return false;
        }
        return true;
    }
};