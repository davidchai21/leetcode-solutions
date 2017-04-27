// Total(6 chips):
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string target="Total(6 chips):";
const vector<string> src={"/Users/davidchai/Desktop/result/GTX480_16/result/","/Users/davidchai/Desktop/result/GTX480_32/result/","/Users/davidchai/Desktop/result/GTX480_64/result/","/Users/davidchai/Desktop/result/GTX480_128/result/"};
const vector<string> file={"output_2DCONV.txt","output_FDTD-2D.txt","output_LPS.txt","output_3MM.txt","output_FWT.txt","output_SLA.txt","output_BlackScholes.txt","output_GEMM.txt","output_SYR2K.txt","output_CONS.txt","output_GESUMMV.txt"};
const string des="/Users/davidchai/Desktop/result/";

void read(string a, string b)
{
    ifstream r(a);
    ofstream f(b,ios_base::app);
    vector<int> res(6,-1);
    string tmp;

    while (!r.eof())
    {
        r.getline(tmp);
        if (tmp==target)
        {
            r>>res[0]>>res[1]>>res[2]>>res[3]>>res[4]>>res[5];
        }
    }
    for (int i=0;i<6;i++)
    {
        f<<res[i]<<"\t";
    }
    f<<endl;
    r.close();
    f.close();
}

int main()
{
    string read,write;
    for (int i=0;i<file.size();i++)
    {
        write=des+file[i];
        for (int j=0;j<src.size();j++)
        {
            read=src[j]+file[i];
            read(read,write);
        }
    }
    cout<<"All files been collected!"<<endl;
    return 0;
}