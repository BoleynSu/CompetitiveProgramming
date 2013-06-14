import java.io.BufferedInputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Scanner in=new Scanner(new BufferedInputStream(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int[] SG=new int[4747+1];
        for (int i=0;i<=4747;i++)
        {
            //SG[i]=mex{SG[t] xor SG[i-1-t] xor 1,SG[t] xor SG[i-2-t]}
            boolean[] mex=new boolean[i+1];
            Arrays.fill(mex, false);
            for (int t=0;t+t+1<=i;t++)
            {
                int get=SG[t]^SG[i-1-t]^1;
                if (get<=i) mex[get]=true;
            }
            for (int t=0;t+t+2<=i;t++)
            {
                int get=SG[t]^SG[i-2-t];
                if (get<=i) mex[get]=true;
            }
            for (int t=0;t<=i;t++)
                if (!mex[t])
                {
                    SG[i]=t;
                    break;
                }
        }
        int T=in.nextInt();
        for (int t=1;t<=T;t++)
        {
            int n=in.nextInt();
            int m=in.nextInt();
            Integer[] p=new Integer[m];
            for (int i=0;i<m;i++)
            {
                p[i]=in.nextInt();
                p[i]=in.nextInt();
                while (p[i]<=0||p[i]>n) p[i]=-1;
            }
            Arrays.sort(p);
            
            int ans=0;
            for (int i=0;i<m;i++)
            {
                ans^=SG[p[i]-(i-1>=0?p[i-1]:0)-1];
                if (i+1<m&&p[i].equals(p[i+1])) i++;
                else ans^=1;
            }
            ans^=SG[n+1-(m-1>=0?p[m-1]:0)-1];
            out.printf("Case %d: %s%n",t,ans==0?"Bob":"Alice");
        }
        in.close();
        out.close();
    }
}
