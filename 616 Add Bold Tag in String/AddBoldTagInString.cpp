class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<int> t(s.size()+1,0);
        for (string l:dict) {
            size_t n=s.find(l);
            while (n!=string::npos) {
                t[n]++;
                t[n+l.size()]--;
                n=s.find(l,n+1);
            }
        }
        string res="";
        int sum=0;
        for (int i=0;i<s.size();i++) {
            if (sum==0 && t[i]>0) res=res+"<b>"+s[i];
            else if (sum>0 && sum+t[i]==0) res=res+"</b>"+s[i];
            else res+=s[i];
            sum+=t[i];
        }
        if (t[s.size()]) res=res+"</b>";
        return res;
    }
};