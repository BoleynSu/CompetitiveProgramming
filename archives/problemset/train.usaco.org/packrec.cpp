/*
ID: sujiao1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("packrec.in");
std::ofstream cout("packrec.out");

struct Program
{
       static const int MAXN=4;
       static const int MAXLEN=200;
       static const int MAXANSWERLEN=384;
       static const int MAXCASE=5;
       struct Box{int a,b;};
       Box* box;
       int sort[MAXN+2];
       int answerl;
       Box answer[MAXANSWERLEN*MAXCASE+2];
       Program():answerl(0)
       {
                box=new Box[MAXN+2];
                for (int i=1;i<=MAXN;i++)
                {
                    cin>>box[i].a>>box[i].b;
                    sort[i]=0;
                }
                /*
                for (int i=1;i<=MAXN;i++)
                {
                    cout<<box[i].a<<" "<<box[i].b<<" \n";
                }
                */
                //while (cin.get()!='q');
                
       }
       ~Program()
       {
                 delete[] box;
       }
       void swap(int& a,int& b)
       {
            int swap=a;
            a=b;
            b=swap;
       }
       void update(int a,int b)
       {
            if ((answerl==0)||(a*b<answer[1].a*answer[1].b))
               answerl=1;
            else if (a*b==answer[1].a*answer[1].b)
                 answerl++;
            else return;
            answer[answerl].a=a;
            answer[answerl].b=b;
       }
       void get()
       {
            //cout<<"get()\n";
            /*
            for (int i=1;i<=4;i++)
                for (int j=1;j<=4;j++)
                    if (sort[j]==i)
                    {
                       cout<<box[j].a<<" "<<box[i].b<<endl;
                    }
            */
            Box* boxbackup=box;
            box=new Box[MAXN+2];
            
            for (int i=1;i<=4;i++)
                for (int j=1;j<=4;j++)
                    if (sort[j]==i)
                    {
                       box[i]=boxbackup[j];
                    }
            
            int a,b;
            //CASE 1
            {
                   a=0;
                   b=0;
                   int maxa=0;
                   int maxb=0;
                   for (int i=1;i<=4;i++)
                   {
                       maxa+=box[i].a;
                       if (box[i].b>maxb) maxb=box[i].b;
                   }
                   if (maxa>a) a=maxa;
                   b=b+maxb;
                   update(a,b);
            }
            //CASE 2
            {
                   a=box[1].a;
                   b=box[1].b;
                   int maxa=0;
                   int maxb=0;
                   for (int i=2;i<=4;i++)
                   {
                       maxa+=box[i].a;
                       if (box[i].b>maxb) maxb=box[i].b;
                   }
                   if (maxa>a) a=maxa;
                   b=b+maxb;
                   update(a,b);
            }
            //CASE 3
            {
                   a=box[1].a;
                   b=box[1].b;
                   int maxa=box[2].a;
                   int maxb=box[2].b;
                   int maxa2=0;
                   int maxb2=0;
                   for (int i=3;i<=4;i++)
                   {
                       maxa2+=box[i].a;
                       if (box[i].b>maxb2) maxb2=box[i].b;
                   }
                   if (maxa2>maxa) maxa=maxa2;
                   maxb=maxb+maxb2;
                   a=a+maxa;
                   if (maxb>b) b=maxb;
                   update(a,b);
            }
            //CASE 4(/5) 
            {
                   a=box[1].a+(box[2].a>box[3].a?box[2].a:box[3].a)+box[4].a;
                   b=box[1].b>box[4].b?box[1].b:box[4].b;
                   if (box[2].b+box[3].b>b) b=box[2].b+box[3].b;
                   update(a,b);
            }
            //CASE 6
            {
                   a=(box[1].a+box[2].a)>(box[3].a+box[4].a)?(box[1].a+box[2].a):(box[3].a+box[4].a);
                   b=0;
                   int maxb1=box[3].b+((a-box[2].a>=box[3].a)?box[1].b:(box[2].b>box[1].b?box[2].b:box[1].b));
                   int maxb2=box[4].b+((a-box[1].a>=box[4].a)?box[2].b:(box[1].b>box[2].b?box[1].b:box[2].b));
                   b=maxb1>maxb2?maxb1:maxb2;
                   update(a,b);
                   //cout<<"update("<<a<<","<<b<<")\n";
            }
            delete[] box;
            box=boxbackup;
       }
       void dfs(int n)
       {
            //cout<<"dfs():\n";
            if (n==MAXN+1) get();
            else
            {
                for (int i=1;i<=4;i++)
                {
                    if (sort[i]==0)
                    {
                       sort[i]=n;
                       dfs(n+1);
                       swap(box[i].a,box[i].b);
                       dfs(n+1);
                       swap(box[i].a,box[i].b);
                       sort[i]=0;
                    }
                }
            }
       }
       int run()
       {
           //cout<<"run()\n";
           dfs(1);
           for (int i=1;i<=answerl;i++)
           {
               if (answer[i].a>answer[i].b) swap(answer[i].a,answer[i].b);
           }
           
           for (int i=1;i<=answerl;i++)
           {
               for (int j=i+1;j<=answerl;j++)
                   if (answer[i].a>answer[j].a)
                   {
                      swap(answer[i].a,answer[j].a);
                      swap(answer[i].b,answer[j].b);
                   }
           }
           
           cout<<answer[1].a*answer[1].b<<endl;
           for (int i=1;i<=answerl;i++)
           {
               while ((answer[i].a==answer[i+1].a)&&(i<answerl)) i++;
               cout<<answer[i].a<<" "<<answer[i].b<<endl;
           }
           return 0;
       }
};

int main()
{
    Program app;
    return app.run();
}
