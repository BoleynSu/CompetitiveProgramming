import java.util.*;
import java.io.*;

public class Main {
    public static void main(String arg[])
    {
        new Main();
    }
    private TreeMap<State,Boolean> f;
    private class State implements Comparable<State>
    {
        private int x;
        String last_three_cards[];
        public State(String cards[],int x)
        {
            this.last_three_cards=new String[3];
            for (int i=0;i<3;i++)
            {
                if (x-3+i>=0) this.last_three_cards[i]=cards[x-3+i];
                else this.last_three_cards[i]=null;
            }
            this.x=x;
        }
        public String toString()
        {
            String s=new String();
            s+=x;
            for (int i=0;i<3;i++)
            {
                if (last_three_cards[i]!=null)
                    s+=last_three_cards[i];
            }
            return s;
        }
        public int compareTo(State other)
        {
            return toString().compareTo(other.toString());
        }
    }
    private boolean dfs(String cards[],int x)
    {
        State s=new State(cards,x);
        if (f.get(s)==null)
        {
            if (x>=4)
            {
                if (cards[x-1].charAt(0)==cards[x-4].charAt(0)||cards[x-1].charAt(1)==cards[x-4].charAt(1))
                {
                    String backup=cards[x-4];
                    cards[x-4]=cards[x-1];
                    if (dfs(cards,x-1)) f.put(s,true);
                    cards[x-4]=backup;
                }
                if (cards[x-1].charAt(0)==cards[x-2].charAt(0)||cards[x-1].charAt(1)==cards[x-2].charAt(1))
                {
                    String backup=cards[x-2];
                    cards[x-2]=cards[x-1];
                    if (dfs(cards,x-1)) f.put(s,true);
                    cards[x-2]=backup;
                }
                if (f.get(s)==null) f.put(s,false);
            }
            else if (x>=2)
            {
                if (cards[x-1].charAt(0)==cards[x-2].charAt(0)||cards[x-1].charAt(1)==cards[x-2].charAt(1))
                {
                    String backup=cards[x-2];
                    cards[x-2]=cards[x-1];
                    if (dfs(cards,x-1)) f.put(s,true);
                    cards[x-2]=backup;
                }
                if (f.get(s)==null) f.put(s,false);
            }
            else f.put(s,true);
        }
        //System.out.println(s.toString()+":"+f.get(s));
        return f.get(s);
    }
    public Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int x=cin.nextInt();
        String cards[]=new String[x];
        for (int i=0;i<x;i++)
            cards[i]=cin.next();
        f=new TreeMap<State,Boolean>();
        System.out.println(dfs(cards,x)?"YES":"NO");
        cin.close();
    }
}
