/*
ID: sujiao1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("runround.in");
std::ofstream cout("runround.out");

struct Program
{
       static const int MAXLEN=9;//1 to 9
       static const int K=10;
       typedef int string[MAXLEN+2]; 
       int M;
       string ms;
       int len;
       bool use[MAXLEN+2];
       Program()
       {
                cin>>M;
       }
       void toString(int M,string ms,int& len)
       {
            len=0;
            for (int k=1;k<M;k*=10)
            {
                len++;
                ms[len]=(M/k)%10;
            }
            for (int i=1;i<=(len+1)/2;i++)
            {
                int swap=ms[i];
                ms[i]=ms[len+1-i];
                ms[len+1-i]=swap;
            }
            /*
            cout<<M<<"after toString:";
            for (int i=1;i<=len;i++)
                cout<<ms[i];
            cout<<endl;
            */
       }
       bool dfs(int pos,string s,int len,int step)
       {
            /*
            cout<<"dfs("<<pos<<",";
            for (int i=1;i<=len;i++)
                cout<<s[i];
            cout<<","<<len<<","<<step<<")\n";
            */
            if ((step==len)&&(pos==1)) return true;
            if (use[pos]) return false;
            use[pos]=true;
            int go=s[pos];
            int newpos=((pos+go)%len==0)?len:(pos+go)%len;
            return dfs(newpos,s,len,step+1);
       }
       bool is(int n)
       {
            //cout<<"is("<<n<<")\n";
            string ns;
            int nlen;
            toString(n,ns,nlen);
            for (int i=1;i<=nlen;i++)
            {
                //there can't be a zero in N
                if (ns[i]==0) return false;
                for (int j=i+1;j<=nlen;j++)
                    //there can't be ns[i] and ns[j] that ns[i]=ns[j] where i!=j
                    if (ns[i]==ns[j])
                       return false;
            }
            for (int i=1;i<=MAXLEN;i++) use[i]=false;
            return dfs(1,ns,nlen,0);
       }
       int run()
       {
           toString(M,ms,len);
           for (int i=M+1;;i++)
           {
               if (is(i))
               {
                  cout<<i<<endl;
                  break;
               }
           }
           return 0;
       }
};

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
    //cout<<clock()<<endl;
}
