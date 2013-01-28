import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String arg[])
    {
        new Main();
    }
    public Main()
    {
        new TaskA();
    }
}

class TaskA
{
    public TaskA()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int a[]=new int[100+2];
        for (int n=1;n<=100;n++)
            if (n%2==0) a[n]=(((n/2-1)*(n/2-1)+1)/2*4);
            else a[n]=((n*n+1)/2);
        int n=cin.nextInt();
        int q=n%4;
        for (int i=1;i<=100;i++)
        {
            if (q==0&&(i%2==0?a[i]>=n:a[i]-1>=n))
            {
                System.out.println(i);
                break;
            }
            else if (q==1&&(i%2==0?false:a[i]>=n))
            {
                System.out.println(i);
                break;
            }
            else if (q==2&&(i%2==0?false:((i+1)/4*4>=2?a[i]-3>=n:false)))
            {
                System.out.println(i);
                break;              
            }
            else if (q==3&&(i%2==0?false:(i/4*4>=2?a[i]-2>=n:false)))           
            {
                System.out.println(i);
                break;              
            }
        }
        cin.close();
    }
}

