
class BinaryFormatExeption extends Throwable
{
	private static final long serialVersionUID = -5907798198474781346L;

	public BinaryFormatExeption(String message)
	{
		super(message);
	}
}
public class TestException4 {
	public long parseBinary(String bin) throws BinaryFormatExeption
	{
		long dec=0;
		for (int i=0;i<bin.length();i++)
		{
			dec<<=1;
			if (bin.charAt(i)=='0') ;
			else if (bin.charAt(i)=='1') dec|=1;
			else throw new BinaryFormatExeption("not a binary number");
		}
		return dec;
	}
	public static void main(String[] args) {
		TestException4 test=new TestException4();
		try
		{
			System.out.println(test.parseBinary("10101010"));
			System.out.println(test.parseBinary("12101010"));
		}
		catch (BinaryFormatExeption e)
		{
			System.out.println(e.getMessage());
		}
		
	}
}
