class Solution {
public:
    string intToRoman(int num) {
        string res="";
        res=head4[num%10]+res; num/=10;
        res=head3[num%10]+res; num/=10;
        res=head2[num%10]+res; num/=10;
        res=head1[num%10]+res; num/=10;
        return res;
    }
private:
    string head1[4]={"","M","MM","MMM"};
    string head2[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string head3[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string head4[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
};