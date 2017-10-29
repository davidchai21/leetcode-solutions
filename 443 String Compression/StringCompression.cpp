class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;
        for (int i=0;i<chars.size();) {
            int j=i+1;
            while (j<chars.size() && chars[j]==chars[i]) j++;
            change(chars,i,j);
        }
        return chars.size();
    }
    void change(vector<char>& chars, int& i, int j) {
        if (j==i+1) i=j;
        else if (j==i+2) {
            chars[i+1]='2';
            i=j;
        }
        else {
            int k=j-i;
            for (int p=to_string(k).size()-1;p>=0;p--) {
                chars[i+1+p]=k%10+'0';
                k/=10;
            }
            chars.erase(chars.begin()+i+to_string(j-i).size()+1,chars.begin()+j);
            i+=to_string(j-i).size()+1;
        }
    }
};