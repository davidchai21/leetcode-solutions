class Solution {
public:
    vector<int> constructRectangle(int area) {
        if (area<=0) return vector<int>(2,0);
        vector<int> res(2,0);
        int w=sqrt(area);
        while (w>=1)
        {
            if (area%w==0)
            {
                res[0]=area/w;
                res[1]=w;
                return res;
            }
            else w--;
        }
    }
};