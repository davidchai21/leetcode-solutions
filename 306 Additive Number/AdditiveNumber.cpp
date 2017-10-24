class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i=1;i<=num.size()*2/3;i++) {
            for (int j=1;j<i;j++) {
                if (check(num.substr(0,j), num.substr(j,i-j), num.substr(i))) return true;
            }
        }
        return false;
    }
    bool check(string a, string b, string num) {
        if (a.size()>1 && a[0]=='0' || b.size()>1 && b[0]=='0') return false;
        string sum=add(a,b);
        if (sum==num) return true;
        if (sum.size()>num.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
        return check(b,sum,num.substr(sum.size()));
    }
    string add(string a, string b) {
        string res="";
        bool flag=false;
        int i=a.size()-1;
        int j=b.size()-1;
        while (flag || i>=0 || j>=0) {
            int t=flag;
            if (i>=0) t+=a[i--]-'0';
            if (j>=0) t+=b[j--]-'0';
            flag=t/10;
            res=to_string(t%10)+res;
        }
        return res;
    }
};