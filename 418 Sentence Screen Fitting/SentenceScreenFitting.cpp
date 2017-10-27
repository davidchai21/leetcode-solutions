class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int,int> m;
        int n=sentence.size();
        for (int i=0;i<n;i++) {
            int l=sentence[i].size();
            if (l>cols) return 0;
            int j=(i+1)%n;
            int count=1;
            while (l+1+sentence[j].size()<=cols) {
                count++;
                l+=1+sentence[j].size();
                j=(j+1)%n;
            }
            m[i]=count;
        }
        int count=0;
        int i=0;
        while (i++<rows) {
            count+=m[count%n];
        }
        return count/n;
    }
};