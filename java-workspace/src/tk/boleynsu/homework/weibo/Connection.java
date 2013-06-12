package tk.boleynsu.homework.weibo;

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
	public List<Microblog> getNewerMicroblog(Microblog first) {
		String sql=null;
		PreparedStatement ps=null;
		ResultSet rs=null;
		try {
			if (first==null)
			{
				sql="select temp.id,nickname,microblog.text,temp.text,temp.time,username,temp.parentId "
					+"from( "
					+"select  microblog.id,nickname,parentId,text,time,username "
					+"from microblog,user "
					+"where user.id=ownerId and (ownerId=? or ownerId in (select followee from isFollowerOf where follower=?)) "
					+"order by microblog.id "
					+")as temp left join microblog on temp.parentId=microblog.id "
					+"limit 0,10; ";
				ps=SQL.prepareStatement(sql);
				ps.setLong(1, uid);
				ps.setLong(2, uid);
			}
			else
			{
				sql="select temp.id,nickname,microblog.text,temp.text,temp.time,username,temp.parentId "
					+"from( "
					+"select  microblog.id,nickname,parentId,text,time,username "
					+"from microblog,user "
					+"where user.id=ownerId and (ownerId=? or ownerId in (select followee from isFollowerOf where follower=?)) and microblog.id>? "
					+"order by microblog.id "
					+")as temp left join microblog on temp.parentId=microblog.id; ";
				ps=SQL.prepareStatement(sql);
				ps.setLong(1, uid);
				ps.setLong(2, uid);
				ps.setLong(3, first.id);
			}
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
			//TODO
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
			//TODO
			return true;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
}
