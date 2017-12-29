class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> dic(26,0);
        for (char a:licensePlate) {
            if (isalpha(a)) {
                dic[tolower(a)-'a']++;
            }
        }
        string res="";
        for (string w:words) {
            if (check(w,dic)) {
                if (res=="" || res.size()>w.size()) res=w;
            }
        }
        return res;
    }
    bool check(string s, vector<int> dic) {
        vector<int> t(26,0);
        for (char a:s) {
            t[a-'a']++;
        }
        for (int i=0;i<26;i++) {
            if (t[i]<dic[i]) return false;
        }
        return true;
    }
};