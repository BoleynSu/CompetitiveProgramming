#include <StandardCodeLibrary>
using namespace StandardCodeLibrary::GraphTheory::MinCostMaxFlow;


int main()
{
	str t;
	cin>>t;
	int n;
	cin>>n;
	vs s(n);
	vi a(n);
	rep(i,n) cin>>s[i]>>a[i];
    memset(adj,0,sizeof(adj)),top=pool;
    S=26+n,T=26+n+1;
	mci cnt;
	rep(i,sz(t)) cnt[t[i]]++;
	ft(i,'a','z') add_edge(i-'a',T,cnt[i],0);
	rep(i,n)
	{
		mci cnt;
		rep(j,sz(s[i])) cnt[s[i][j]]++;
		ft(j,'a','z') add_edge(26+i,j-'a',cnt[j],i+1);
		add_edge(S,26+i,a[i],0);
	}
	int flow,cost;
	min_cost_max_flow(flow,cost);
	if (flow!=sz(t)) cout<<-1<<endl;
	else cout<<cost<<endl;
}
