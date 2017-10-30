class Solution {
public:
    int myAtoi(string str) {
        long res=0;
        int sign=1;
        bool flag=true;
        int i=0;
        while (i<str.size() && str[i]==' ') i++;
        if (str[i]=='+' || str[i]=='-') {
            sign=str[i++]=='+'?1:-1;
            while (i<str.size() && isdigit(str[i])) {
                res=res*10+str[i]-'0';
                if (res>INT_MAX) break;
                i++;
            }
        }
        else if (isdigit(str[i])) {
            while (i<str.size() && isdigit(str[i])) {
                res=res*10+str[i]-'0';
                if (res>INT_MAX) break;
                i++;
            }
        }
        if (res*sign>INT_MAX) return INT_MAX;
        else if (res*sign<INT_MIN) return INT_MIN;
        return (int)res*sign;
    }
};