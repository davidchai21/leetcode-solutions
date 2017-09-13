class Solution {
public:
    bool judgeCircle(string moves) {
        int width=0;
        int height=0;
        for (int i=0;i<moves.size();i++)
        {
            if (moves[i]=='U') height++;
            else if (moves[i]=='D') height--;
            else if (moves[i]=='L') width--;
            else width++;
        }
        return height==0 && width==0;
    }
};