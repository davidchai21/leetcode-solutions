class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(),str.end());
        for (int i=0,j=0;i<str.size();i=j+1) {
            for (j=i;j<str.size() && !isspace(str[j]);j++);
            reverse(str.begin()+i,str.begin()+j);
        }
    }
};