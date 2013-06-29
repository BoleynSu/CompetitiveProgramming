package tk.boleynsu.homework.weibo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

public class SQL
{
	private static Connection connection=null;
	private static Connection getConnection() throws ClassNotFoundException, SQLException
	{
		if (connection==null||connection.isClosed())
		{
			Class.forName("com.mysql.jdbc.Driver");
			connection=DriverManager.getConnection("jdbc:mysql://"+Config.getSqlHost()+"/"+Config.getSqlDatabase(),Config.getSqlUsername(),Config.getSqlPassword());
		}
		return connection;
	}
	public static PreparedStatement prepareStatement(String sql) throws ClassNotFoundException, SQLException
	{
		return getConnection().prepareStatement(sql);
	}
	public static Statement createStatement() throws ClassNotFoundException, SQLException
	{
		return getConnection().createStatement();
	}
	public static void main(String[] args) throws ClassNotFoundException, SQLException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection connection=DriverManager.getConnection("jdbc:mysql://"+Config.getSqlHost(),Config.getSqlUsername(),Config.getSqlPassword());
		Statement statement=connection.createStatement();
		statement.execute("create database "+Config.getSqlDatabase()+";");
		statement.execute("use "+Config.getSqlDatabase()+";");
		statement.execute("create table userInfo(id bigint auto_increment primary key,usrename varchar(16) not null,password char(128) not null,name varchar(5) not null,sex bit not null,birthday date not null,place varchar(20) not null,income bigint,height int,weight int,degree varchar(10));");
	}
}
