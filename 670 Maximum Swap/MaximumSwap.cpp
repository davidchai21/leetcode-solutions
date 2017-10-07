class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        bool flag=true;
        for (int i=0;i<s.size() && flag;i++) {
            int end=s.size()-1;
            int index=end-1;
            while (index>i) {
                if (s[index]>s[end]) end=index;
                index--;
            }
            if (s[end]>s[i]) {
                flag=false;
                swap(s[i],s[end]);
            }
        }
        return stoi(s);
    }
};