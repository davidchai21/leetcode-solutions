class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size();
        int n=num2.size();
        vector<int> a(m+n,0);
        for (int i=m-1;i>=0;i--)
        {
            for (int j=n-1;j>=0;j--)
            {
                int t=(num1[i]-'0')*(num2[j]-'0')+a[i+j+1];
                a[i+j+1]=t%10;
                a[i+j]+=t/10;
            }
        }
        string res="";
        int i=0;
        while (a[i]==0) i++;
        for (;i<m+n;i++)
        {res.push_back(a[i]+'0');}
        if (!res.empty())
        return res;
        else return "0";
    }
};