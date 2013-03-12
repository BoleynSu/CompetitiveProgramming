lexrq<pr<cost_type,int> > Q;
		d[S]=0,p[S]=0,Q.push(mp(-d[S],S));
		whl(sz(Q))
		{
			int u=Q.top().y;
			Q.pop();
			if (!inq[u])
			{
				inq[u]=true;
				for (edge i=adj[u];i;i=i->n)
				{
					if (i->c&&!inq[i->v]&&cmin(d[i->v],d[u]+i->d+h[u]-h[i->v]))
						p[i->v]=i,Q.push(mp(-d[i->v],i->v));
					if (i->c) asrtWA(i->d+h[u]-h[i->v]>=0);
				}
			}
		}
		if (d[T]==oo) break;
		else
		{
			flow_type delta=oo;
			for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
			for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta,cost+=delta*i->d;
			flow+=delta;
			rep(i,V) h[i]+=d[i];
		}
	}
}

}
}
}

using namespace StandardCodeLibrary::GraphTheory::MinCostMaxFlow;

int main()
{
    int Tc;
    scanf("%d",&Tc);
    for (int t=0;t<Tc;t++)
    {
        int N;
        scanf("%d",&N);
        build_graph(1,N);
        for (;;)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if (!u) break;
            add_edge(u,v,1,w);
            add_edge(v,u,1,w);
        }
        int cost,flow;
        V=N+2;
        min_cost_max_flow(flow,cost);
        if (N==1) puts("0");
        else printf("%d\n",flow);
    }
}


























