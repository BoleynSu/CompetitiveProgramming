import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] arg)
    {
        new Main();
    }
    int[] state;
    static final int oo=4;
    static final int[] edgeu={0,1,3,11,10,8,4,5,7,15,14,12,9,9,9,2,2,2,13,13,13,6,6,6,0,1,3,11,10,8,9,2};
    static final int[] edgev={1,3,11,10,8,0,5,7,15,14,12,4,1,8,11,0,3,10,5,12,15,4,7,14,4,5,7,15,14,12,13,6};
    int dfs(int a,int c)
    {
        if (a+c>=oo) return oo;
        else if (a==0) return c;
        else
        {
            int min=oo;
            for (int i=0;i<32;i++)
            {
                if ((state[edgeu[i]]==1)^(state[edgev[i]]==1))
                {
                    int swap,ba=a;
                    swap=state[edgeu[i]];
                    state[edgeu[i]]=state[edgev[i]];
                    state[edgev[i]]=swap;
                    if (edgeu[i]<8)
                    {
                        if (state[edgeu[i]]==1) a++;
                        else a--;
                    }
                    if (edgev[i]<8)
                    {
                        if (state[edgev[i]]==1) a++;
                        else a--;
                    }
                    if (a+c+1<min)
                    {
                        int get=dfs(a,c+1);
                        if (min>get) min=get;
                    }
                    a=ba;
                    swap=state[edgeu[i]];
                    state[edgeu[i]]=state[edgev[i]];
                    state[edgev[i]]=swap;
                }
            }
            return min;
        }
    }
    Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int T=cin.nextInt();
        for (int t=1;t<=T;t++)
        {
            state=new int[16];
            int a=0,b=0;
            for (int i=0;i<8;i++)
            {
                state[i]=cin.nextInt();
                if (state[i]==1) a++;
            }
            for (int i=8;i<16;i++)
            {
                state[i]=cin.nextInt();
                if (state[i]!=1) b++;
            }
            int answer;
            if (a==b) answer=dfs(a,0);
            else answer=oo;
            System.out.println("Case #"+t+": "+((answer==oo)?"more":answer));
        }
        cin.close();
    }
}

