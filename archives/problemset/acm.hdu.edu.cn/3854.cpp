#include <iostream>
#include <cstring>
using namespace std;

const int MAXN=100000+2;

int N,m,K;
int a[MAXN];
int c[MAXN];
int cuts;
int cut[MAXN];
int ta[2][MAXN];
long long int answer_result;

void inc(int* ta,int position,int delta)
{
     while (position<=N)
     {
           ta[position]+=delta;
           position+=position&(-position);
     }
}
long long int query(int* ta,int QL,int QR)
{
     if (QL>QR) return 0;
     
     int sum=0;
     QL--;
     while (QL>0)
     {
           sum-=ta[QL];
           QL-=QL&(-QL);
     }
     while (QR>0)
     {
           sum+=ta[QR];
           QR-=QR&(-QR);
     }
     return sum;
}
void prepare()
{
     cuts=0;
     cut[cuts++]=0;
     for (int i=1;i<=N;i++)
         if (a[i]<K) cut[cuts++]=i;
     cut[cuts]=N+1;
     
     memset(ta,0,sizeof(ta));
     for (int i=1;i<=N;i++)
         inc(ta[c[i]],i,+1);
     
     answer_result=0;
     for (int i=1;i<cuts;i++)
     {
         for (int color=0;color<2;color++)
             answer_result+=query(ta[color],cut[i-1],cut[i]-1)*query(ta[!color],cut[i],N);
         answer_result+=query(ta[!c[cut[i]]],cut[i]+1,cut[i+1]-1); 
     }
}
long long int answer()
{
    return answer_result;
}
void change(int position)
{
     int L=0,R=cuts;
     while (L+1!=R)
     {
           int mid=(L+R)>>1;
           if (cut[mid]<position) L=mid;
           else R=mid;
     }
     if (cut[R]==position)
     {
        answer_result-=query(ta[!c[position]],1,N);
        inc(ta[c[position]],position,-1);
        c[position]=!c[position];
        inc(ta[c[position]],position,+1);
        answer_result+=query(ta[!c[position]],1,N);
     }
     else
     {
         answer_result-=query(ta[!c[position]],1,cut[L])+query(ta[!c[position]],cut[R],N);
         inc(ta[c[position]],position,-1);
         c[position]=!c[position];
         inc(ta[c[position]],position,+1);
         answer_result+=query(ta[!c[position]],1,cut[L])+query(ta[!c[position]],cut[R],N);
     }
}

int main()
{ 
    int Q;
    cin>>Q;
    for (int q=1;q<=Q;q++)
    {
        cin>>N>>m>>K;
        for (int i=1;i<=N;i++) cin>>a[i];
        for (int i=1;i<=N;i++) cin>>c[i];
        prepare();
        for (int i=1;i<=m;i++)
        {
            int query;
            cin>>query;
            if (query) cout<<answer()<<endl;
            else cin>>query,change(query);
        }
    }
}

