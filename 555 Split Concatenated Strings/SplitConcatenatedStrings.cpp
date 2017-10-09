class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        flip(strs);
        string res="";
        for (int i=0;i<strs.size();i++) update(strs,res,i);
        return res;
    }
    void flip(vector<string>& s) {
        for (int i=0;i<s.size();i++) {
            string t=s[i];
            reverse(t.begin(),t.end());
            if (t>s[i]) s[i]=t;
        }
    }
    void update(vector<string> s, string& res, int pos) {
        string base="";
        for (int i=pos+1;i<pos+s.size();i++) {
            base+=s[i%s.size()];
        }
        for (int i=0;i<s[pos].size();i++) {
            string t=s[pos].substr(i,s[pos].size()-i)+base+s[pos].substr(0,i);
            if (t>res) res=t;
        }
        string a=s[pos];
        reverse(a.begin(),a.end());
        for (int i=0;i<a.size();i++) {
            string t=a.substr(i,a.size()-i)+base+a.substr(0,i);
            if (t>res) res=t;
        }
    }
};