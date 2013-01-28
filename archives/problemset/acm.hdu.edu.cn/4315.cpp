/*
AUTHOR: Su Jiao
DATE: 2010-6-19
DESCRIPTION:
http://acm.pku.edu.cn/JudgeOnline/problem?id=1704
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::sort;

class Application
{
    int N,K;
    vector<int> P;
    string get()
    {
        if (K==1) return "Alice";
        int SG=(N&1)?P[0]-(K==2):0;
        for (int i=N-2;i>=0;i-=2)
            SG^=P[i+1]-P[i]-1;
        if (SG) return "Alice";
        else return "Bob";
    }
    public:
    Application()
    {
                std::ios::sync_with_stdio(false);
    }
    int run()
    {
        while (cin>>N>>K)
        {
            P.resize(N);
            for (int j=0;j<N;j++)
                cin>>P[j];
            cout<<get()<<endl;
            P.clear();
        }
        return 0;
    }
};

int main()
{
    Application app;
    return app.run();
}

