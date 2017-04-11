class Solution {
public:
    char findTheDifference(string s, string t) {
        char res=0;
        for (char a:s) res^=a;
        for (char a:t) res^=a;
        return res;
        
    }
};