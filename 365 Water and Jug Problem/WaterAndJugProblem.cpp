class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z==0) return true;
        if (x==0 || y==0) return (z==max(x,y));
        int n=gcd(x,y);
        if (z%n || n>z || z>x+y) return false;
        return true;
    }
    int gcd(int a, int b)
    {
        if (a==b) return a;
        int m=max(a,b);
        int n=min(a,b);
        if (n==0) return m;
        else if (n==1) return 1;
        else
        {return gcd(n,m-n);}
    }
};