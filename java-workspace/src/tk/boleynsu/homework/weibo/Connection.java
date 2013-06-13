package tk.boleynsu.homework.weibo;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class Connection {
	private long uid;
	public boolean login(String username,String md5)
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select id from user where username=? and password=?;");
			ps.setString(1,username);
			ps.setString(2,md5);
			rs=ps.executeQuery();
			if (!rs.next()) return false;
			uid=rs.getLong(1);
			return true;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
	public boolean register(String username,String nickname,String md5)
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select id from user where username=?;");
			ps.setString(1,username);
			rs=ps.executeQuery();
			if (rs.next()) return false;
			ps=SQL.prepareStatement("insert into user(username,nickname,password) values(?,?,?);");
			ps.setString(1, username);
			ps.setString(2, nickname);
			ps.setString(3, md5);
			ps.execute();
			return true;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
	public String getUsername()
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select username from user where id=?;");
			ps.setLong(1,uid);
			rs=ps.executeQuery();
			if (!rs.next()) return null;
			String username=rs.getString(1);
			return username;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
		
	}
	public String getNickname()
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select nickname from user where id=?;");
			ps.setLong(1,uid);
			rs=ps.executeQuery();
			if (!rs.next()) return null;
			String nickname=rs.getString(1);
			return nickname;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	public Long getFollowerNumber()
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select count(*) from isFollowerOf where followee=?;");
			ps.setLong(1,uid);
			rs=ps.executeQuery();
			if (!rs.next()) return null;
			return rs.getLong(1);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	public Long getFolloweeNumber()
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select count(*) from isFollowerOf where follower=?;");
			ps.setLong(1,uid);
			rs=ps.executeQuery();
			if (!rs.next()) return null;
			return rs.getLong(1);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	public Long getMicroblogNumber()
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select count(*) from microblog where ownerId=?;");
			ps.setLong(1,uid);
			rs=ps.executeQuery();
			if (!rs.next()) return null;
			return rs.getLong(1);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	public List<Microblog> getNewerMicroblog() {
		String sql=null;
		PreparedStatement ps=null;
		ResultSet rs=null;
		try {
			sql="select temp.id,nickname,microblog.text,temp.text,temp.time,username,temp.parentId "
				+"from( "
				+"select  microblog.id,nickname,parentId,text,time,username "
				+"from microblog,user "
				+"where user.id=ownerId and (ownerId=? or ownerId in (select followee from isFollowerOf where follower=?)) "
				+"order by microblog.id desc"
				+")as temp left join microblog on temp.parentId=microblog.id; ";
			ps=SQL.prepareStatement(sql);
			ps.setLong(1, uid);
			ps.setLong(2, uid);
			rs=ps.executeQuery();
			List<Microblog> fetch=new ArrayList<Microblog>();
			while (rs.next())
			{
				sql="select count(*) from microblog where parentId=?;";
				ps=SQL.prepareStatement(sql);
				ps.setLong(1, rs.getLong(1));
				ResultSet nrs=ps.executeQuery();
				if (nrs.next())
					fetch.add(new Microblog(rs.getLong(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5),rs.getString(6),rs.getLong(7),nrs.getLong(1)));
			}
			return fetch;
		} catch (SQLException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		return null;
	}
	public List<Microblog> getNewerAt() {
		String sql=null;
		PreparedStatement ps=null;
		ResultSet rs=null;
		try {
			sql="select temp.id,nickname,microblog.text,temp.text,temp.time,username,temp.parentId "
				+"from( "
				+"select  microblog.id,nickname,parentId,text,time,username "
				+"from microblog,user "
				+"where microblog.ownerId=user.id and microblog.id in (select mid from hasAtTag where uid=?) "
				+"order by microblog.id desc"
				+")as temp left join microblog on temp.parentId=microblog.id; ";
			ps=SQL.prepareStatement(sql);
			ps.setLong(1, uid);
			rs=ps.executeQuery();
			List<Microblog> fetch=new ArrayList<Microblog>();
			while (rs.next())
			{
				sql="select count(*) from microblog where parentId=?;";
				ps=SQL.prepareStatement(sql);
				ps.setLong(1, rs.getLong(1));
				ResultSet nrs=ps.executeQuery();
				if (nrs.next())
					fetch.add(new Microblog(rs.getLong(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5),rs.getString(6),rs.getLong(7),nrs.getLong(1)));
			}
			return fetch;
		} catch (SQLException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		return null;
	}
	public String getNicknameByMicroblogId(long id)
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select nickname from user,microblog where microblog.id=? and microblog.ownerId=user.id;");
			ps.setLong(1,id);
			rs=ps.executeQuery();
			if (!rs.next()) return null;
			return rs.getString(1);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	public Long getUserIdByMicroblogId(long id)
	{
		PreparedStatement ps;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select ownerId from microblog where microblog.id=?;");
			ps.setLong(1,id);
			rs=ps.executeQuery();
			if (!rs.next()) return null;
			return rs.getLong(1);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	public List<User> getFolloweeList() {
		String sql=null;
		PreparedStatement ps=null;
		ResultSet rs=null;
		try {
			ps=SQL.prepareStatement(";");
			sql="select id,username,nickname "
				+"from user "
				+"where id in (select followee from isFollowerOf where follower=?);";
			ps=SQL.prepareStatement(sql);
			ps.setLong(1, uid);
			rs=ps.executeQuery();
			List<User> fetch=new ArrayList<User>();
			while (rs.next())
			{
				fetch.add(new User(rs.getLong(1),rs.getString(2),rs.getString(3)));
			}
			return fetch;
		} catch (SQLException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		return null;
	}
	public List<User> getFollowerList() {
		String sql=null;
		PreparedStatement ps=null;
		ResultSet rs=null;
		try {
			ps=SQL.prepareStatement(";");
			sql="select id,username,nickname "
				+"from user "
				+"where id in (select follower from isFollowerOf where followee=?);";
			ps=SQL.prepareStatement(sql);
			ps.setLong(1, uid);
			rs=ps.executeQuery();
			List<User> fetch=new ArrayList<User>();
			while (rs.next())
			{
				fetch.add(new User(rs.getLong(1),rs.getString(2),rs.getString(3)));
			}
			return fetch;
		} catch (SQLException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		return null;
	}
	public boolean post(String microblog)
	{
		PreparedStatement ps;
		Statement st;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("insert into microblog(ownerId,text) values(?,?);");
			ps.setLong(1,uid);
			ps.setString(2,microblog);
			ps.execute();
			st=SQL.createStatement();
			rs=st.executeQuery("select last_insert_id();");
			if (!rs.next()) return false;
			long mid=rs.getLong(1);
			at(microblog,mid);
			return true;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
	public boolean repost(String microblog, long parent) {
		PreparedStatement ps;
		Statement st;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("insert into microblog(ownerId,parentId,text) values(?,?,?);");
			ps.setLong(1,uid);
			ps.setLong(2,parent);
			ps.setString(3,microblog);
			ps.execute();
			st=SQL.createStatement();
			rs=st.executeQuery("select last_insert_id();");
			if (!rs.next()) return false;
			long mid=rs.getLong(1);
			at(microblog,mid);
			ps=SQL.prepareStatement("insert into hasAtTag values(?,?);");
			ps.setLong(1, mid);
			ps.setLong(2, getUserIdByMicroblogId(parent));
			ps.execute();
			return true;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
	private void at(String microblog, long mid) {
		for (int i=0;i<microblog.length();i++)
			if (microblog.charAt(i)=='@')
			{
				int j;
				for (j=i+1;j<microblog.length();j++)
					if (Character.isSpaceChar(microblog.charAt(j)))
						break;
				String get=microblog.substring(i+1, j);
				PreparedStatement ps;
				ResultSet rs;
				try {
					ps=SQL.prepareStatement("select id from user where nickname=?;");
					ps.setString(1,get);
					rs=ps.executeQuery();
					if (!rs.next()) continue;
					long uid=rs.getLong(1);
					ps=SQL.prepareStatement("insert into hasAtTag values(?,?);");
					ps.setLong(1, mid);
					ps.setLong(2, uid);
					ps.execute();
				} catch (ClassNotFoundException e) {
					e.printStackTrace();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
	}
	public boolean follow(String nickname) {
		PreparedStatement ps;
		Statement st;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select id from user where nickname=?;");
			ps.setString(1,nickname);
			rs=ps.executeQuery();
			if (!rs.next()) return false;
			long uid=rs.getLong(1);
			ps=SQL.prepareStatement("insert into isFollowerOf values(?,?);");
			ps.setLong(1, this.uid);
			ps.setLong(2, uid);
			ps.execute();
			return true;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
	public boolean unfollow(String nickname) {
		PreparedStatement ps;
		Statement st;
		ResultSet rs;
		try {
			ps=SQL.prepareStatement("select id from user where nickname=?;");
			ps.setString(1,nickname);
			rs=ps.executeQuery();
			if (!rs.next()) return false;
			long uid=rs.getLong(1);
			ps=SQL.prepareStatement("delete from isFollowerOf where follower=? and followee=?;");
			ps.setLong(1, this.uid);
			ps.setLong(2, uid);
			ps.execute();
			return true;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
	public static void main(String[] arg) throws NoSuchAlgorithmException
	{
		String password="abc";
		String pwd=new String(password.toLowerCase());
		MessageDigest messageDigest = MessageDigest.getInstance("md5");
		String md5=new BigInteger(1,messageDigest.digest(pwd.getBytes())).toString(16);
		new Connection().register("a@b.c", "TEST", md5);
	}
}
