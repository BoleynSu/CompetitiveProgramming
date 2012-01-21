#include <iostream>
#include <string>
using namespace std;

char out[10];
int k;

void get(char* zl,char* zr,char* hl,char** hr)
{
     char* root=zl;
     for (;root<=zr;root++)
         if (*root==**hr) break;
     (*hr)--;
     if (root<zr) get(root+1,zr,hl,hr);
     if (zl<root) get(zl,root-1,hl,hr);
     out[k++]=*root;
}

int main()
{
    char z[10],h[10];
    cin>>z>>h;
    char* tmp=(char*)(h+strlen(h)-1);
    get(z,z+strlen(z)-1,h,&tmp);
    for (int i=k-1;i>=0;i--) cout<<out[i];
    cout<<endl;    
    //while (cin.get());
}
