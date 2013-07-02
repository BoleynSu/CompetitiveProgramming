#include <Math>

db r1,r2;
db f(db x){rtn x;}
int main()
{
	cin>>r1>>r2;
	if (r1>r2) swap(r1,r2);
	pdb(4,integrate(0,r1,f))<<endl;
}
