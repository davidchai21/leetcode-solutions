class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        bool flag=false;
        int m=a.size(); int n=b.size();
        for (int i=0;i<m || i<n;i++)
        {
            int t=0;
            if (i<m) t+=a[i]-'0';
            if (i<n) t+=b[i]-'0';
            if (flag) t+=1;
            if (t==0) {res='0'+res; flag=false;}
            else if (t==1) {res="1"+res; flag=false;}
            else if (t==2) {res="0"+res; flag=true;}
            else if (t==3) {res="1"+res; flag=true;}
        }
        if (flag) {res="1"+res;}
        return res;
    }
};