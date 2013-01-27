#include <cstdio>
#include <deque>
using namespace std;

int N;
deque<int> box[100+1];

int main()
{
	scanf("%d",&N);
	for (int i=0;i<N;i++)
	{
		int ID,M;
		scanf("%d%d",&ID,&M);
		box[M].push_back(ID);
	}
	for (int m=100;m>=0;m--)
	{
		while (!box[m].empty())
			printf("%d %d\n",box[m].front(),m),box[m].pop_front();
	}
	return 0;
}