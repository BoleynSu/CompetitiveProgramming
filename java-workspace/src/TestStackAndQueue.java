
abstract class Fruit
{
	public abstract void printName();
}
class Apple extends Fruit
{
	public void printName()
	{
		System.out.println("Apple");
	}
}
class Pear extends Fruit
{
	public void printName()
	{
		System.out.println("Pear");
	}
}
class Peach extends Fruit
{
	public void printName()
	{
		System.out.println("Peach");
	}
}

public class TestStackAndQueue {

	public static void main(String[] args) {
		Queue<Integer> q=new Queue<Integer>();
		q.put(1);
		q.put(2);
		q.put(-1);
		System.out.println(q.get());
		System.out.println(q.get());
		System.out.println(q.get());
		Queue<String> q2=new Queue<String>();
		q2.put("a");
		q2.put("c");
		q2.put("d");
		System.out.println(q2.get());
		System.out.println(q2.get());
		System.out.println(q2.get());
		Stack<Integer> s=new Stack<Integer>();
		s.push(1);
		s.push(2);
		s.push(-1);
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		Stack<String> s2=new Stack<String>();
		s2.push("a");
		s2.push("c");
		s2.push("d");
		System.out.println(s2.pop());
		System.out.println(s2.pop());
		System.out.println(s2.pop());
		Queue<Fruit> qf=new Queue<Fruit>();
		Stack<Fruit> sf=new Stack<Fruit>();
		qf.put(new Apple());
		qf.put(new Pear());
		qf.put(new Peach());
		qf.get().printName();
		qf.get().printName();
		qf.get().printName();
		sf.push(new Apple());
		sf.push(new Pear());
		sf.push(new Peach());
		sf.pop().printName();
		sf.pop().printName();
		sf.pop().printName();
	}

}
