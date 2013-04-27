import java.io.IOException;


class UndefinedOptionException extends RuntimeException
{
	private static final long serialVersionUID = 5206121424810666637L;

	public UndefinedOptionException(String message)
	{
		super(message);
	}
}

public class TestException2 {
	public static void main(String[] args) throws IOException
	{
		try
		{
			System.out.println("Input 'Y' to continue, 'N' to quit.");
			int c=System.in.read();
			if (c=='Y')
			{
				System.out.println("continue");
			}
			else if (c=='N')
			{
				System.out.println("quit");
			}
			else throw new UndefinedOptionException("You should input either 'Y' or 'N'.");
		}
		catch (UndefinedOptionException e)
		{
			System.out.println(e.getMessage());
		}
	}
}
