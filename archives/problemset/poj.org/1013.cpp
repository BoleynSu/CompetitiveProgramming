#include <iostream>
using std::cin; 
using std::cout; 
using std::endl; 

void answer();

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        answer();
    return 0;
}

void answer()
{
    char input[3][3][1024];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            cin>>input[i][j];
    
    bool pool[1024][3];
    for (int i=0;i<1024;i++)
        for (int j=0;j<3;j++)
            pool[i][j]=false;
    
    int count=-1;
    for (int j=0;j<3;j++)
    {
        int l,h;
        
        if (input[j][2][0]=='u')
        {
           count++;
           l=1;
           h=0;
        }
        if (input[j][2][0]=='d')
        {
           count++;
           l=0;
           h=1;
        }
        
        if (input[j][2][0]=='e')
        {
           for (int i=0;input[j][0][i]!='\0';i++) pool[input[j][0][i]][1]=true;
           for (int i=0;input[j][1][i]!='\0';i++) pool[input[j][1][i]][1]=true;
        }
        else if (count==0)
        {
           for (int i=0;input[j][l][i]!='\0';i++) pool[input[j][l][i]][0]=true;
           for (int i=0;input[j][h][i]!='\0';i++) pool[input[j][h][i]][2]=true;
        }
        else 
        {
            for (char k='A';k<='L';k++)//FOR 'A' TO 'L' 如果 不在 这行数据中的都能平衡 
            {
                bool find=false;
                for (int i=0;input[j][l][i]!='\0';i++)
                    if (input[j][l][i]==k) find=true;
                for (int i=0;input[j][h][i]!='\0';i++)
                    if (input[j][h][i]==k) find=true;
                if (!find) pool[k][1]=true;
            }
            for (int i=0;input[j][l][i]!='\0';i++)//FOREACH CHAR IN LIGHT 如果原来不是LIGHT则可平衡 
                if (!pool[input[j][l][i]][0]) pool[input[j][l][i]][1]=true;
            for (int i=0;input[j][h][i]!='\0';i++)//FOREACH CHAR IN HEAVY 如果原来不是HEAVY则可平衡 
                if (!pool[input[j][h][i]][2]) pool[input[j][h][i]][1]=true;
        }
        /*
        for (char k='A';k<='L';k++)
            cout<<k<<":"<<pool[k][0]<<pool[k][1]<<pool[k][2]<<'\t';
        cout<<endl;*/
    }
    
    int count2[3]={0,0,0};
    char data[3];
    char k='A';
    for (;k<='L';k++)
    {
        if (!pool[k][1])
        {
           if (pool[k][0]){count2[0]++;data[0]=k;}
           if (pool[k][2]){count2[2]++;data[2]=k;}
        }
    }
    if (count2[0]==1) cout<<data[0]<<" is the counterfeit coin and it is light."<<endl;
    if (count2[2]==1) cout<<data[2]<<" is the counterfeit coin and it is heavy."<<endl;
}
