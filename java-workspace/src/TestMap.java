import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

public class TestMap {
	public static void main(String[] args) throws IOException
	{
		FileReader fr=new FileReader(args[0]);
		Scanner s=new Scanner(fr);
		int wordCounter=0;
		TreeMap<String,ArrayList<Integer>> position=new TreeMap<String,ArrayList<Integer>>();
		while (s.hasNextLine())
		{
			String[] words=s.nextLine().toLowerCase().split("[^a-zA-Z]+");
			for (String word:words)
			{
				ArrayList<Integer> set=position.get(word);
				if (set==null)
				{
					set=new ArrayList<Integer>();
					position.put(word,set);
				}
				set.add(++wordCounter);
			}
		}
		Iterator<Entry<String,ArrayList<Integer>>> it=position.entrySet().iterator();
		while (it.hasNext())
		{
			Entry<String,ArrayList<Integer>> entry=it.next();
			System.out.print(entry.getKey()+":");
			for (Integer p:entry.getValue()) System.out.print(" "+p);
			System.out.println();
		}
	}
}
