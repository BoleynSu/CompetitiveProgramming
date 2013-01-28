#include <cstdio>
#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n,k;
	cin>>n>>k;
	vector<pair<int,int> > h(n);
	for (int i=0;i<n;i++) cin>>h[i].first,h[i].second=i;
	sort(h.begin(),h.end(),greater<pair<int,int> >());
	cout<<h[k-1].first<<endl;
	for (int i=0;i<k;i++) h[i].first=h[i].second;
	sort(h.begin(),h.begin()+k);
	for (int i=0;i<k;i++) cout<<h[i].first+1<<char(i+1==k?'\n':' ');
}

