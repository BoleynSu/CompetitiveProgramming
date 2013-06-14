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
		statement.execute("create table user(id bigint auto_increment primary key,username varchar(255) unique not null,nickname varchar(255) unique not null,password char(128) not null);");
		statement.execute("create table microblog(id bigint auto_increment primary key,parentId bigint,ownerId bigint not null,text varchar(140) not null,time timestamp,foreign key(parentId) references microblog(id),foreign key(ownerId) references user(id));");
		statement.execute("create table isFollowerOf(follower bigint,followee bigint,primary key(follower,followee),foreign key(follower) references user(id),foreign key(followee) references user(id));");
		statement.execute("create table hashTag(id bigint auto_increment primary key,text varchar(140) unique not null);");
		statement.execute("create table hasHashTag(mid bigint,hid bigint,primary key(mid,hid),foreign key(mid) references microblog(id),foreign key(hid) references hashTag(id));");
		statement.execute("create table hasAtTag(mid bigint,uid bigint,primary key(mid,uid),foreign key(mid) references microblog(id),foreign key(uid) references user(id));");
	}
}
