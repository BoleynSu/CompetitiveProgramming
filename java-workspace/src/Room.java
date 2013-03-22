import java.util.*;
import java.io.*;
class Room{
   static int TotalType;//种类总数
   double perCharge;//每天收费
   String RoomType;//房间类型名
   String RoomDes;//房间细节
   static Room room[]=new Room[10];
   
   static double RoomCharge(int TypeNum,int RoomNumber,int RoomDay)//计算总住宿费
   { 
       double charge;
       charge=RoomNumber*RoomDay*room[TypeNum].perCharge;
       return charge;
   }

   void Detail(int type)//显示该type的细节给用户
   {
       System.out.println(room[type].RoomType);
       System.out.println(room[type].RoomDes);
       System.out.println(room[type].perCharge);
   }

   static void menu()//显示房间清单
   {
       int i;
       for(i=0;i<TotalType;i++)
       {
           System.out.println(i+"."+room[i].RoomType);
       }
   }

   static void Read(String source) throws IOException//从文件名为args[0]中读取房间数据并存入数组中
   {
       room=new Room[10];
       String s;
       int i=0;
       BufferedReader br=new BufferedReader(new FileReader(source));
       TotalType=Integer.parseInt(br.readLine());//读入总类型数
       //System.out.println(TotalType);
       while((s=br.readLine())!=null)
       {
            System.out.println(s);
            StringTokenizer st=new StringTokenizer(s,"|");
            try{
                 while(st.hasMoreTokens())
                 {
                     if(i%3==0){room[i/3]=new Room();room[i/3].RoomType=st.nextToken();System.out.println(room[i/3].RoomType);}
                     if(i%3==1){room[(i-1)/3]=new Room();room[(i-1)/3].RoomDes=st.nextToken();System.out.println(room[(i-1)/3].RoomDes);}
                     if(i%3==2){room[(i-2)/3]=new Room();room[(i-2)/3].perCharge=Double.parseDouble(st.nextToken());System.out.println(room[(i-2)/3].perCharge);}
                     i++;
                 }
            }catch(java.lang.NullPointerException e){System.out.println("Something Wrong!");}
       }
       br.close();
   }

   static void Write(int TypeNum,int RoomNumber,int RoomDay,PrintWriter pw)//把用户住房记录追加写入文件中
   {
      pw.println(RoomNumber+" "+room[TypeNum].RoomType+
       " has/have been occupied for "+RoomDay+" day(s).");
   }

   public static void main(String args[]) throws IOException{
      room=new Room[10];
      PrintWriter pw;
      pw=new PrintWriter(new FileWriter(args[1],true));    
      Scanner scan=new Scanner(System.in);
      String ch;
      int typeno=0,roomnum=0,day=0;
      double charge=0;
      Read(args[0]);
      for(;;)
      {
        System.out.println("Do you want to book rooms?(Y/N)");
        ch=scan.next();
        if(ch.equals("Y"))
        {
            System.out.println("Please enter the number of type of room you want to book.");
            menu();
            typeno=scan.nextInt();
            System.out.println("Please enter the number of rooms you want to book.");
            roomnum=scan.nextInt();
            System.out.println("Please enter the days you want to stay in the rooms.");
            day=scan.nextInt();
            charge=RoomCharge(typeno,roomnum,day);
            System.out.println("The total charge is "+charge+" dollars.");
            Write(typeno,roomnum,day,pw);
             
        }
        else if(ch.equals("N"))
        {
            break;
        }
        else
        {
            System.out.println("Please enter Y or N.Other characters will not work.");
        }
   
      
      }
}

}



