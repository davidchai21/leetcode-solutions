class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.size()==0 || heaters.size()==0) return false;
        int res=0;
        int index=0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        for (int i=0;i<houses.size();i++)
        {
            while (index<heaters.size()-1 && abs(houses[i]-heaters[index])>=abs(houses[i]-heaters[index+1]))
            {
                index++;
            }
            res=max(res,abs(houses[i]-heaters[index]));
        }
        return res;
    }
};