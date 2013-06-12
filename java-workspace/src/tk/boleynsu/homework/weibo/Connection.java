package tk.boleynsu.homework.weibo;

public class Connection {
	private String username;
	public boolean login(String username,char[] password)
	{
		this.username=username;
		return username.equals(new String(password));
	}
	public String getUsername()
	{
		return username;
	}
}
