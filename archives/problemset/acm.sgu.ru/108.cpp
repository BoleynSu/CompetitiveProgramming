/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-12-03
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N;
int K;
int S[5000];

int qh;
pair<int,int> q[5000];
int is_not_self_number[128];
int self_numbers_count;
int answer[5000];

int main()
{
    cin>>N>>K;
    for (int i=0;i<K;i++)
        cin>>S[i],q[i].first=S[i],q[i].second=i;
    sort(q,q+K);
    for (int i=1;i<=N;i++)
    {
        int get=i,digits=i;
        while (digits) get+=digits%10,digits/=10;
        if (get<=N) is_not_self_number[(get)&127]=true;
        if (!is_not_self_number[i&127])
        {
           self_numbers_count++;
           while (qh<K&&q[qh].first==self_numbers_count) answer[q[qh++].second]=i;
        }
        else is_not_self_number[i&127]=false;
    }
    cout<<self_numbers_count<<endl;
    for (int i=0;i<K;i++)
        cout<<answer[i]<<char(i+1==K?'\n':' ');
}
