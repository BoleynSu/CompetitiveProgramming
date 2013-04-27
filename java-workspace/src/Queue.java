import java.util.LinkedList;


public class Queue<T> {
	private LinkedList<T> list=new LinkedList<T>();
	public void put(T e)
	{
		list.add(e);
	}
	public T get()
	{
		T e=list.getFirst();
		list.removeFirst();
		return e;
	}
}
