/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-11
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[])
    {
        new Main();
    }
    public int N,M;
    public String message[],mask[],words[];
    public String get_answer()
    {
        StringBuffer masks[][]=new StringBuffer[4][N];
        for (int i=0;i<N;i++)
            masks[0][i]=new StringBuffer(mask[i]);
        for (int i=1;i<4;i++)
            for (int x=0;x<N;x++)
            {
                masks[i][x]=new StringBuffer();
                masks[i][x].setLength(N);
                for (int y=0;y<N;y++)
                    masks[i][x].setCharAt(y,masks[i-1][N-1-y].charAt(x));
            }
        StringBuffer answers_[]=new StringBuffer[4];
        for (int start=0;start<4;start++)
        {
            answers_[start]=new StringBuffer();
            for (int offset=0;offset<4;offset++)
            {
                int now=(start+offset)%4;
                for (int x=0;x<N;x++)
                    for (int y=0;y<N;y++)
                        if (masks[now][x].charAt(y)=='*')
                        {
                            char get=message[x].charAt(y);
                            if (get=='.')
                            {
                                if (answers_[start].length()!=0&&answers_[start].charAt(answers_[start].length()-1)!=' ')
                                    answers_[start].append(' ');
                            }
                            else answers_[start].append(get);
                        }
            }
            while (answers_[start].length()!=0&&answers_[start].charAt(answers_[start].length()-1)==' ')
                answers_[start].deleteCharAt(answers_[start].length()-1);
        }
        String answers[]=new String[4];
        for (int i=0;i<4;i++) answers[i]=new String(answers_[i]);
        Arrays.sort(answers);
        for (int start=0;start<4;start++)
        {
            String set[]=answers[start].split(" ");
            boolean possible=true;
            for (int i=0;i<set.length;i++)
            {
                boolean possible_=false;
                for (int j=0;j<M;j++)
                {
                    if (set[i].equals(words[j])) possible_=true;
                }
                if (!possible_)
                {
                    possible=false;
                    break;
                }
            }
            if (possible) return answers[start];
        }
        return "FAIL TO DECRYPT";
    }
    public Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int T=cin.nextInt();
        for (int t=1;t<=T;t++)
        {
            N=cin.nextInt();
            message=new String[N];
            mask=new String[N];
            cin.nextLine();
            for (int i=0;i<N;i++)
                message[i]=cin.nextLine();
            for (int i=0;i<N;i++)
                mask[i]=cin.nextLine();
            M=cin.nextInt();
            cin.nextLine();
            words=new String[M];
            for (int i=0;i<M;i++)
                words[i]=cin.nextLine();
            System.out.println("Case #"+t+": "+get_answer());
        }
    }
}

