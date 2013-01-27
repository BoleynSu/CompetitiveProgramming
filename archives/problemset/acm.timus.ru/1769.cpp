#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
#include <set>

std::string string;
long long int answer;
bool set[10000000];

int main()
{
    //freopen("out.txt","w",stdout);
    cin>>string;
    for (long long int i=10,k=1;;i*=10,k++)
    {
        long long int now=0;
        for (int j=0;j<k;j++) now=now*10+string[j]-'0';
        set[now]=true;
        for (int j=k;j<string.length();j++)
            set[now=(now*10+string[j]-'0')%i]=true;
        bool getanswer=false;
        for (answer=i/10;answer<i;answer++)
            if (set[answer]) set[answer]=false;
            else
            {
                getanswer=true;
                break;
            }
        if (answer<i) getanswer=true;
        if (getanswer) break;
    }
    cout<<answer<<endl;
}
