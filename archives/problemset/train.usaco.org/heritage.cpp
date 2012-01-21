/*
ID: sujiao1
PROG: heritage
LANG: C++
*/
/*
PROGRAM: heritage
AUTHOR: Su Jiao
DATE: 2009-12-27
DESCRIPTION:
农夫约翰非常认真地对待他的奶牛们的血统。然而他不是一个真正优秀的记帐员。他把他
的奶牛们的家谱作成二叉树，并且把二叉树以更线性
的”树的中序遍历“和”树的前序遍历“的符号加以记录而不是用图形的方法。
你的任务是在被给予奶牛家谱的”树中序遍历“和”树前序遍历“的符号后，创建奶牛家
谱的”树的后序遍历“的符号。每一头奶牛的姓名被
译为一个唯一的字母。（你可能已经知道你可以在知道树的两种遍历以后可以经常地重建
这棵树。）显然，这里的树不会有多余26个的顶点。
这是在样例输入和样例输出中的树的图形表达方式：
                  C
                /   \
               /     \
              B       G
             / \     /
            A   D   H
               / \
              E   F
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
#include <string>
using std::string;

class Application
{
      ifstream cin;
      ofstream cout;
      string LDR;//IN-ORDER
      string DLR;//PRE-ORDER
      //string LRD;//POST-ORDER
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>LDR>>DLR;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      void print(int is,int ie,int& ps,int& pe)
      {
           if (is>ie) return;
           char root=DLR[ps];
           ps++;
           int rp;
           for (int i=is;i<=ie;i++)
           {
               if (LDR[i]==root)
                  rp=i;
           }
           print(is,rp-1,ps,pe);
           print(rp+1,ie,ps,pe);
           cout<<root;
      }
      int run()
      {
          int s=0,e=DLR.length()-1;
          print(0,LDR.length()-1,s,e);
          cout<<endl;
          return 0;
      }
};

int main()
{
    Application app("heritage.in","heritage.out");
    return app.run();
}
