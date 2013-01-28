#include <cstdio>
#include <map>
#include <string>
using namespace std;

int t;
map<string,int> Haab_s2i;
map<int,string> Tzolkin_i2s;
char buffer[1024];


int main()
{
    Haab_s2i["pop"]=0;
    Haab_s2i["no"]=1;
    Haab_s2i["zip"]=2;
    Haab_s2i["zotz"]=3;
    Haab_s2i["tzec"]=4;
    Haab_s2i["xul"]=5;
    Haab_s2i["yoxkin"]=6;
    Haab_s2i["mol"]=7;
    Haab_s2i["chen"]=8;
    Haab_s2i["yax"]=9;
    Haab_s2i["zac"]=10;
    Haab_s2i["ceh"]=11;
    Haab_s2i["mac"]=12;
    Haab_s2i["kankin"]=13;
    Haab_s2i["muan"]=14;
    Haab_s2i["pax"]=15;
    Haab_s2i["koyab"]=16;
    Haab_s2i["cumhu"]=17;
    Haab_s2i["uayet"]=18;
    Tzolkin_i2s[0]="imix";
    Tzolkin_i2s[1]="ik";
    Tzolkin_i2s[2]="akbal";
    Tzolkin_i2s[3]="kan";
    Tzolkin_i2s[4]="chicchan";
    Tzolkin_i2s[5]="cimi";
    Tzolkin_i2s[6]="manik";
    Tzolkin_i2s[7]="lamat";
    Tzolkin_i2s[8]="muluk";
    Tzolkin_i2s[9]="ok";
    Tzolkin_i2s[10]="chuen";
    Tzolkin_i2s[11]="eb";
    Tzolkin_i2s[12]="ben";
    Tzolkin_i2s[13]="ix";
    Tzolkin_i2s[14]="mem";
    Tzolkin_i2s[15]="cib";
    Tzolkin_i2s[16]="caban";
    Tzolkin_i2s[17]="eznab";
    Tzolkin_i2s[18]="canac";
    Tzolkin_i2s[19]="ahau";
    scanf("%d",&t);
    printf("%d\n",t);
    for (int i=0;i<t;i++)
    {
        int D,M,Y;
        scanf("%d. %s %d",&D,buffer,&Y);
        M=Haab_s2i[buffer];
        int d=Y*365+M*20+D;
        printf("%d %s %d\n",d%13+1,Tzolkin_i2s[d%20].c_str(),d/260);
    }
    return 0;
}
