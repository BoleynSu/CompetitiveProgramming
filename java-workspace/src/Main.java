import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

class AccountException extends Exception
{
	private static final long serialVersionUID = -6650019591373965372L;

	AccountException(String message)
	{
		super(message);
	}
}

class Account
{
	
	private String name;
	private int number;
	private int balance;
	private static int counter=0;
	
	public Account(String name,int number)
	{
		this.name=name;
		this.number=number;
		this.balance=0;
		Account.counter++;
	}
	
	public void deposit(int money)
	{
		this.balance+=money;
	}
	
	public void withdraw(int money) throws AccountException
	{
		if (money>this.balance) throw new AccountException("You can't withdraw so much money.");
		this.balance-=money;
	}
	
	public String getInformation()
	{
		return "Name of account holder: "+this.name+" Account number: "+this.number+" Balance: "+this.balance;
	}
	
	public static int getCounter()
	{
		return Account.counter;
	}

	public boolean isNumber(int number) {
		return this.number==number;
	}

}

class AccountManager
{
	private ArrayList<Account> accounts;
	private Scanner in;
	private PrintStream out;
	
	public AccountManager(InputStream in,PrintStream out)
	{
		accounts=new ArrayList<Account>();
		this.in=new Scanner(in);
		this.out=out;
	}
	
	private int getIndex(int number)
	{
		int index=-1;
		for (int i=0;i<accounts.size();i++)
			if (accounts.get(i).isNumber(number))
				index=i;
		return index;
	}
	
	private void createAccount(int number)
	{
		out.println("Oops! Your account number is wrong!");
		out.println("Enter q to quit or c to create an account.");
		String cmd=in.next();
		if (cmd.equals("q")) return;
		out.println("Please enter your name to create an account.");
		String name=in.next();
		accounts.add(new Account(name,number));
	}
	
	public void serve()
	{
		out.println("============================================================");
		out.println("Welcome!");
		out.println("We have "+Account.getCounter()+" account(s).");
		out.println("Please enter your account number to continue the service.");
		int number=in.nextInt();
		int index=getIndex(number);
		if (index==-1)
		{
			createAccount(number);
			index=getIndex(number);
		}
		if (index!=-1)
		{
			Account currentAccount=accounts.get(index);
			out.println("Your account information:");
			out.println(currentAccount.getInformation());
			boolean quit=false;
			while (!quit)
			{
				out.println("Please choose an operation you will perform:");
				out.println("1. Query");
				out.println("2. Deposit");
				out.println("3. Withdraw");
				out.println("4. Quit");
				int operation=in.nextInt();
				switch (operation)
				{
				case 1:
					out.println("Your account information:");
					out.println(currentAccount.getInformation());
					break;
				case 2:
					out.println("How much will you deposit?");
					int depositMoney=in.nextInt();
					currentAccount.deposit(depositMoney);
					out.println("Accepted.");
					break;
				case 3:
					out.println("How much will you withdraw?");
					int withdrawMoney=in.nextInt();
					try
					{
						currentAccount.withdraw(withdrawMoney);
						out.println("Accepted.");
					}
					catch (AccountException e)
					{
						out.println("Rejected.");
						out.println(e.getMessage());
					}
					break;
				case 4:
					quit=true;
					break;
				default:
					break;
				}
			}
		}
		out.println("Bye!");
		out.println("============================================================");
	}

	public void run()
	{
		while (true)
		{
			serve();
		}
	}
}

public class Main
{
	public static void main(String[] arg)
	{
		new Main();
	}
	Main()
	{
		AccountManager accountManager=new AccountManager(System.in,System.out);
		accountManager.run();
	}
}
