#include <iostream>
using namespace std;

int main()
{
    int mother=0;
    int have=0;
    int fail=false;
    for (int i=1;i<=12;i++)
    {
        have+=300;
        int use;
        cin>>use;
        int last=have-use;
        if ((last<0)&&(!fail)){cout<<-i<<endl;fail=true;}
        int save=last-last%100;
        mother+=save;
        last-=save;
        have=last;
    }
    if (!fail) cout<<(mother/100)*120+have<<endl;
    return 0;
}
