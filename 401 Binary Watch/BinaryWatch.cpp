class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<vector<string>> hour;
    hour.push_back(vector<string> {"0"});
    hour.push_back(vector<string> {"1", "2", "4", "8"});
    hour.push_back(vector<string> {"3", "5", "6", "9", "10"});
    hour.push_back(vector<string> {"7", "11"});

    vector<vector<string>> minute;
    minute.push_back(vector<string> {"00"});
    minute.push_back(vector<string> {"01", "02", "04", "08", "16", "32"});
    minute.push_back(vector<string> {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"});
    minute.push_back(vector<string> {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"});
    minute.push_back(vector<string> {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"});
    minute.push_back(vector<string> {"31", "47", "55", "59"});

    int numHour = max(0, num - 5), numMinute = min(5, num);
    vector<string> ans;
    if (num > 8 || num < 0)
    	return ans;
    while (numHour <= min(num, 3)) {
    	for (auto h : hour[numHour]) 
    	    for (auto m : minute[numMinute]) 
    		ans.push_back(h+":"+m);
    	numHour++;
    	numMinute--;
    }
    return ans;
    }
};