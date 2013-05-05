import java.util.Arrays;


public class WolfInZooDivOne {
	public int count(int N, String[] L, String[] R)
	{
		String sl="",sr="";
		for (String i:L) sl=sl+i;
		for (String i:R) sr=sr+i;
		String[] sli=sl.split(" "),sri=sr.split(" ");
		int M=sli.length;
		int[] l=new int[M],r=new int[M];
		for (int i=0;i<M;i++)
		{
			l[i]=Integer.parseInt(sli[i])+1;
			r[i]=Integer.parseInt(sri[i])+1;
		}
		System.out.println(M);
		for (int i=0;i<M;i++)
			System.out.println(l[i]+" "+r[i]);
		int[] ed=new int[N+1];
		for (int i=0;i<=N;i++)
			ed[i]=i;
		for (int i=0;i<M;i++)
			ed[l[i]]=Math.min(ed[l[i]],r[i]);
		for (int i=1;i<=N;i++) ed[i]=Math.max(ed[i-1], ed[i]);
		long[][][] f=new long[N+1][N+1][3];
		for (int i=0;i<=N;i++)
			for (int j=0;j<=N;j++)
				Arrays.fill(f[i][j],-1);
		for (int i=0;i<=N;i++)
		{
			f[i][i][0]=1;
			f[i][][1]=j-i+1;
			f[i][j][2]=(j-i+1)*(j-i)/2;
		}
		for (int i=0;i<=N;i++)
		{
			for (int length=1;length<=N-i+1;length++)
			{
				int j=i+length-1;
				f[i][j][k]=f[i][j-1][k]+f[i][j-1][k]
			}
		}
		long ans=0;
		
		return (int)ans;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		WolfInZooDivOne instance=new WolfInZooDivOne();
		instance.count(
				100,
				new String[]{"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"},
				new String[]{"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"});
	}

}
