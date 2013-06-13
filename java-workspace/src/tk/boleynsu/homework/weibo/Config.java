package tk.boleynsu.homework.weibo;

public class Config
{
	private static String sqlHost;
	private static String sqlUsername;
	private static String sqlPassword;
	private static String sqlDatabase;
	static
	{
		Config.setSqlHost("localhost");
		Config.setSqlUsername("root");
		Config.setSqlPassword("iamroot");
		Config.setSqlDatabase("weibo");
	}
	public static String getSqlHost() {
		return sqlHost;
	}
	public static void setSqlHost(String sqlHost) {
		Config.sqlHost = sqlHost;
	}
	public static String getSqlUsername() {
		return sqlUsername;
	}
	public static void setSqlUsername(String sqlUsername) {
		Config.sqlUsername = sqlUsername;
	}
	public static String getSqlPassword() {
		return sqlPassword;
	}
	public static void setSqlPassword(String sqlPassword) {
		Config.sqlPassword = sqlPassword;
	}
	public static String getSqlDatabase() {
		return sqlDatabase;
	}
	public static void setSqlDatabase(String sqlDatabase) {
		Config.sqlDatabase = sqlDatabase;
	}
}
