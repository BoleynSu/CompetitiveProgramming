#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<bool> get(n,false);
    int answer=0;
    for (int i=0;i<n;i++)
    {
        int ai;
        cin>>ai;
        if (get[ai]||ai>n) answer++;
        else get[ai]=true;
    }
    cout<<answer<<endl;
    return 0;
}

