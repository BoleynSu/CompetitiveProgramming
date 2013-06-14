package tk.boleynsu.homework;

import java.util.concurrent.Semaphore;

public class DiningPhilosophersProblem
{
	static Semaphore[] forks;
	class Philosopher implements Runnable
	{
		int id;
		Philosopher(int id)
		{
			this.id=id;
		}
		public void run()
		{
			for (;;)
			{
				try {
					Thread.sleep((long) (Math.random()*5000));
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				if (forks[id].tryAcquire())
				{
					if (forks[(id+1==forks.length?0:id+1)].tryAcquire())
					{
					}
					else
					{
						forks[id].release();
						continue;
					}
				}
				else
				{
					continue;
				}
				System.out.println("philosopher "+id+" eating...");
				try {
					Thread.sleep((long) (Math.random()*5000));
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				forks[id].release();
				forks[(id+1==forks.length?0:id+1)].release();
				System.out.println("philosopher "+id+" thinking...");
			}
		}
	}
	public static void main(String[] arg)
	{
		DiningPhilosophersProblem diningPhilosophersProblem=new DiningPhilosophersProblem();
		forks=new Semaphore[5];
		for (int i=0;i<forks.length;i++)
			forks[i]=new Semaphore(1);
		Philosopher[] philosophers=new Philosopher[5];
		for (int i=0;i<philosophers.length;i++)
		{
			philosophers[i]=diningPhilosophersProblem.new Philosopher(i);
		}
		for (int i=0;i<philosophers.length;i++)
		{
			new Thread(philosophers[i]).start();
		}
	}
}
