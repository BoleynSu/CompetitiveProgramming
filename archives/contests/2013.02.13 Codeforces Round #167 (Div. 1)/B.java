import java.io.BufferedInputStream;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;


public class Main {
	public static void main(String[] arg)
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		int[] a=new int[n],b=new int[n];
		for (int i=0;i<n;i++) a[i]=cin.nextInt();
		for (int i=0;i<n;i++) b[i]=cin.nextInt();
		int m=cin.nextInt();
		
		Map<Integer,Integer> tot=new TreeMap<Integer,Integer>(),rep=new TreeMap<Integer,Integer>();
		for (int i=0;i<n;i++)
		{
			if (tot.get(a[i])==null) tot.put(a[i],0);
			if (tot.get(b[i])==null) tot.put(b[i],0);
			if (rep.get(a[i])==null) rep.put(a[i],0);
			if (rep.get(b[i])==null) rep.put(b[i],0);
			tot.put(a[i],tot.get(a[i])+1);
			tot.put(b[i],tot.get(b[i])+1);
			if (a[i]==b[i])
			{
				rep.put(a[i],rep.get(b[i])+1);
			}
		}
		
		long ans=1;
		Iterator it=tot.entrySet().iterator();
		while (it.hasNext())
		{
			Entry et=(Entry)it.next();
			int key=(int)et.getKey(),value=(int)et.getValue();
			int count=rep.get(key);
			long get=1;
			for (int i=1;i<=value;i++)
			{
				int x=i;
				while (count!=0&&x%2==0)
				{
					x/=2;
					count--;
				}
				get*=x;
				get%=m;
			}
			ans*=get;
			ans%=m;
		}
		System.out.println(ans);
		cin.close();
	}
}

