/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-6-12
DESCRIPTION:
http://acm.hdu.edu.cn/showproblem.php?pid=2222
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include <string.h>
#define H(c) ((c)-'a')
#define NEXT_SIZE ('z'-'a'+1)
#define NODE_SIZE 500000
#define QUEUE_SIZE 500000
#define NEW 1
#define DELETE 2

struct node
{
       node* fail;
       node* next[NEXT_SIZE];
       int count;
};
node* get(int flag=0)
{
      static node* pool;
      static int top;
      if (!flag)
      {
         memset(pool+top,0,sizeof(node));
         return pool+top++;
      }
      else
      {
         switch (flag)
         {
                case NEW:
                     pool=new node[NODE_SIZE];
                     top=0;
                     break;
                case DELETE:
                     delete[] pool;
                     break;
         }
         return 0;
      }
}
void insert(node* const root,const char* str)
{
     node* p=root;
     do
     {
           if (!p->next[H(*str)]) p->next[H(*str)]=get();
           p=p->next[H(*str)];
     }
     while (*(++str));
     p->count++;
}
void build_ac_automation(node* const root)
{
     static node* q[QUEUE_SIZE];
     node** head;
     node** tail;
     *(head=tail=q)=root;
     while (head<=tail)
     {
           node* qh=*(head++);
           for (int i='a';i<='z';i++)
               if (qh->next[H(i)])
               {
                  if (qh==root) qh->next[H(i)]->fail=root;
                  else
                  {
                      node* p=qh->fail;
                      while (p)
                      {
                            if (p->next[H(i)])
                            {
                               qh->next[H(i)]->fail=p->next[H(i)];
                               break;
                            }
                            p=p->fail;
                      }
                      if (!p) qh->next[H(i)]->fail=root;
                  }
                  *(++tail)=qh->next[H(i)];
               }
     }
}
int query(node* const root,const char* str)
{
    int result=0;
    node* p=root;
    do
    {
      while (!p->next[H(*str)]&&p!=root) p=p->fail;
      p=p->next[H(*str)];
      if (!p) p=root;
      node* t=p;
      while (t!=root)
      {
            result+=t->count;
            t->count=0;
            t=t->fail;
      }
    }
    while (*(++str));
    return result;
}

class Application
{
      int CASE,N;
      string keywords;
      string description;
      public:
      Application()
      {
                   std::ios::sync_with_stdio(false);
                   cin>>CASE;
      }
      int run()
      {
          for (int i=0;i<CASE;i++)
          {
              get(NEW);
              cin>>N;
              node* root=get();
              for (int j=0;j<N;j++)
              {
                  cin>>keywords;
                  insert(root,keywords.c_str());
              }
              build_ac_automation(root);
              cin>>description;
              cout<<query(root,description.c_str())<<endl;
              get(DELETE);
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}

