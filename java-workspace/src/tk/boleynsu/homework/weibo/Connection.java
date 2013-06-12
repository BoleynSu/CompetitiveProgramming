package tk.boleynsu.homework.weibo;

import java.math.BigInteger;
import java.net.URL;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.ImageIcon;

public class Connection {
	private String username;
	public boolean login(String username,char[] password)
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			this.username=username;
			String pwd=new String(password).toLowerCase();
			MessageDigest messageDigest=MessageDigest.getInstance("md5");
			String md5=new BigInteger(1,messageDigest.digest(pwd.getBytes())).toString(16);
			ps = SQL.prepareStatement("select id from user where username=? and password=?;");
			ps.setString(1,username);
			ps.setString(2,md5);
			rs=ps.executeQuery();
			return rs.next();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		}
		return false;
	}
	public String getUsername()
	{
		return username;
	}
	public boolean post(String weibo)
	{
		PreparedStatement ps;
		Statement st;
		ResultSet rs;
		try {
			ps = SQL.prepareStatement("insert into microblog(text) values(?);");
			ps.setString(1, weibo);
			ps.execute();
			st=SQL.createStatement();
			rs=st.executeQuery("select last_insert_id();");
			if (!rs.next()) return false;
			long mid=rs.getLong(1);
			System.out.println(mid);
			return true;
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
}
