#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int T;
    for (scanf("%d",&T);T;T--)
    {
        int N;
        scanf("%d",&N);
        double a[N],b[N],c[N];
        for (int i=0;i<N;i++) scanf("%lf%lf%lf",a+i,b+i,c+i);
        double l=-1e10,r=-1e10;
        for (int i=0;i<N;i++)
        {
            if (abs(a[i])<1e-5)
            {
                double ml=c[i];
                double mr=1e3*b[i]+c[i];
                double min=ml<mr?ml:mr,max=ml>mr?ml:mr;
                if (min>l) l=min;
                if (max>r) r=max;
            }
            else
            {
                double delta=b[i]*b[i]-4*a[i]*c[i];
                double min=-delta/(4.0*a[i]);
                double maxl=c[i];
                double maxr=1e6*a[i]+1e3*b[i]+c[i];
                if (min>l) l=min;
                if (maxl>r) r=maxl;
                if (maxr>r) r=maxr;
            }
        }
        while ((r-l)>1e-5)
        {
              double mid=(l+r)/2;
              double lc=0,rc=1e4;
              for (int i=0;i<N;i++)
              {
                  if (abs(a[i])<1e-5)
                  {
                     if (abs(b[i])<1e-5)
                     {
                        //do nothing
                     }
                     else
                     {
                         double x=(mid-c[i])/b[i];
                         if (b[i]>0)
                         {
                            if (rc>x) rc=x;
                         }
                         else
                         {
                             if (lc<x) lc=x;
                         }
                     }
                  }
                  else
                  {
                      double delta=b[i]*b[i]-4*a[i]*(c[i]-mid);
                      double sqrt_delta=sqrt(delta);
                      double lci=(-b[i]-sqrt_delta)/(2.0*a[i]);
                      double rci=(-b[i]+sqrt_delta)/(2.0*a[i]);
                      if (lc<lci) lc=lci;
                      if (rc>rci) rc=rci;
                  }
              }
              if (lc<rc) r=mid;
              else l=mid;
        }
        if (abs(r)<1e-5) printf("0.0000\n");
        else printf("%.4f\n",r);
    }
}

