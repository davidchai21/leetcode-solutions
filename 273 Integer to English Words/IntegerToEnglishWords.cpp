class Solution {
public:
    string numberToWords(int num) {
        if (num==0) return "Zero";
        string s="";
        int low=num%1000;
        int mid=(num/1000)%1000;
        int high=(num/1000/1000)%1000;
        int super=(num/1000/1000/1000)%1000;
        if (super)
        {
            s+=helper(super);
            s+=" Billion";
        }
        if (high)
        {
            if (super) s+=" ";
            s+=helper(high);
            s+=" Million";
        }
        if (mid)
        {
            if (super || high) s+=" ";
            s+=helper(mid);
            s+=" Thousand";
        }
        if (low)
        {
            if (super || high || mid) s+=" ";
            s+=helper(low);
        }
        return s;
    }
    
    string helper(int n)
    {
        string res="";
        string d1[10]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string d11[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string d10[8]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        if (n<10) return d1[n];
        else if (n>=10 && n<20) return d11[n%10];
        else if (n>=20 && n<100) 
        {
            res+=d10[n/10-2];
            if (n%10)
            {
                res+=" ";
                res+=d1[n%10];
            }
        }
        else
        {
            res+=d1[n/100];
            res+=" Hundred";
            int t=n%100;
            if (t==0) return res;
            res+=" ";
            if (t<10) res+=d1[t];
            else if (t>=10 && t<20) res+=d11[t%10];
            else if (t>=20 && t<100) 
            {
                res+=d10[t/10-2];
                if (t%10)
                {
                    res+=" ";
                    res+=d1[t%10];
                }
            }
        }
        return res;
    }
};