class Solution {
public:
    string fractionAddition(string expression) {
        int i=1;
        int n=expression.size();
        string res="0/1";
        if (n==0) return res;
        while (i<n) {
            int j=i-1;
            while (i<n && (expression[i]!='+' && expression[i]!='-')) i++;
            res=helper(res,expression.substr(j,i-j));
            i++;
        }
        return res;
    }
    pair<int,int> parse(string a){
        int i=0;
        while (a[i]!='/') i++;
        int x=stoi(a.substr(0,i));
        int y=stoi(a.substr(i+1,a.size()-i-1));
        return make_pair(x,y);
    }
    string helper(string res,string a) {
        pair<int,int> x=parse(res);
        pair<int,int> y=parse(a);
        int top=x.first*y.second+x.second*y.first;
        int down=x.second*y.second;
        if (top==0) return "0/1";
        int g=gcd(abs(top),down);
        return to_string(top/g)+"/"+to_string(down/g);
    }
    int gcd(int a,int b) {
        int x=max(a,b);
        int y=min(a,b);
        int t=x%y;
        while (t) {
            x=y;
            y=t;
            t=x%y;
        }
        return y;
    }
};