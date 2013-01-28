/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;
import java.util.Comparator;

public class Main {
    public static void main(String args[])
    {
        new Main();
    }
    private class Segment {public double a,b;};
    private class MyComparator implements Comparator<Segment>
    {
        public int compare(Segment a,Segment b)
        {
            if (a.a<b.a) return -1;
            else return +1;
        }
    }
    private Scanner cin;
    private int get()
    {
        int n=cin.nextInt();
        double x[]=new double[n],y[]=new double[n],r[]=new double[n];
        for (int i=0;i<n;i++)
        {
            x[i]=cin.nextInt();
            y[i]=cin.nextInt();
            r[i]=cin.nextInt();
        }
        int answer=0;
        for (int ux=0,uy=5000;ux<uy;ux++)
        {
            double u=Math.PI*ux/uy;
            Segment s[]=new Segment[n];
            for (int i=0;i<n;i++)
            {
                s[i]=new Segment();
                double c=Math.sin(u)*x[i]+Math.cos(u)*y[i];
                s[i].a=c-r[i];
                s[i].b=c+r[i];
            }
            Arrays.sort(s,new MyComparator());
            PriorityQueue<Double> q=new PriorityQueue<Double>();
            for (int i=0;i<n;i++)
            {
                q.add(s[i].b);
                while (q.size()>0)
                {
                    if (q.peek()<s[i].a-1e-2) q.remove();
                    else break;
                }
                if (q.size()>answer) answer=q.size();
            }
        }
        return answer;
    }
    public Main()
    {
        cin=new Scanner(new BufferedInputStream(System.in));
        int T=cin.nextInt();
        for (int t=1;t<=T;t++) System.out.printf("Case #%d: %d\n",t,get());
    }
}

