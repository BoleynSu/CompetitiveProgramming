import java.util.LinkedList;

public class Stack<T> {
	private LinkedList<T> list=new LinkedList<T>();
	public void push(T e)
	{
		list.add(e);
	}
	public T pop()
	{
		T e=list.getLast();
		list.removeLast();
		return e;
	}
}
