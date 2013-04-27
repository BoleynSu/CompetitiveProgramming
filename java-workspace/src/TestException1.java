
public class TestException1 {
	public static void main(String[] args)
	{
		try
		{
			int[] a=new int[3];
			for (int i=0;i<=3;i++) a[i]=i;
		}
		catch (ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Array index out of bounds!");
		}
	}
}
