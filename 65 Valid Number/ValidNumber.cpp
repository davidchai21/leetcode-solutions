class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        while (s[i]==' ') i++;
        int j=s.size()-1;
        while (s[j]==' ') j--;
        if (i>j) return false;
        string a=s.substr(i,j-i+1);
        i=0;
        bool f=false;
        
        j=0;
        while (!isalpha(a[j]) && j<a.size()) j++;
        if (!check_num(a,i,j,true)) return false;
        if (j>=a.size()) return true;
        if (a[j]=='e') j++;
        if (j>=a.size()) return false;
        return check_num(a,j,a.size(),false);
    }
private:
    bool check_num(string s, int i, int j, bool front)
    {
        if (i==j) return false;
        string a=s.substr(i,j-i);
        int x=0;
        if (a[x]=='+' || a[x]=='-') x++;
        if (x>=a.size()) return false;
        int c=0; // float point
        bool f=false;
        while (x<a.size())
        {
            if (a[x]=='.') c++;
            else if (isdigit(a[x])) {f=true;}
            else return false;
            x++;
        }
        if (!f || (front && c>1) || (!front && c>0)) return false;
        return true;
    }
};