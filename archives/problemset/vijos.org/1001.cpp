#include <iostream>
#include <string>
using namespace std;

struct Student
{
       string mingzhi;
       int qimo,banji;
       char ganbu,xibu;
       int lunwen;
       int total;
};

void deal(Student& stu)
{
     stu.total=0;
     if ((stu.qimo>80)&&(stu.lunwen>=1)) stu.total+=8000;
     if ((stu.qimo>85)&&(stu.banji>80)) stu.total+=4000;
     if (stu.qimo>90) stu.total+=2000;
     if ((stu.qimo>85)&&(stu.xibu=='Y')) stu.total+=1000;
     if ((stu.banji>80)&&(stu.ganbu=='Y')) stu.total+=850;
}

void get()
{
     int N;
     Student* stu;
     cin>>N;
     stu=new Student[N];
     int total=0;
     int max=0;
     
     for (int i=0;i<N;i++)
     {
         cin>>stu[i].mingzhi>>stu[i].qimo>>stu[i].banji
         >>stu[i].ganbu>>stu[i].xibu>>stu[i].lunwen;
         deal(stu[i]);
         total+=stu[i].total;
         if (stu[i].total>stu[max].total) max=i;
     }
     
     cout<<stu[max].mingzhi<<endl
     <<stu[max].total<<endl
     <<total<<endl;
     
     delete[] stu;
}

int main()
{
    get();
    return 0;
}
