package tk.boleynsu.homework;

import java.util.concurrent.Semaphore;

public class ProducerConsumerProblem
{
	int head,tail;
	int[] buffer;
	Semaphore full,empty,mutex;
	public ProducerConsumerProblem(int n)
	{
		head=0;
		tail=0;
		buffer=new int[n];
		full=new Semaphore(0);
		empty=new Semaphore(n);
		mutex=new Semaphore(1);
	}
	class Proceducer implements Runnable
	{
		int id;
		public Proceducer(int id)
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
				if (mutex.tryAcquire())
				{
					if (empty.tryAcquire())
					{
					}
					else
					{
						mutex.release();
						continue;
					}
				}
				else continue;
				buffer[tail%buffer.length]=(int) Math.round(Math.random()*Integer.MAX_VALUE);
				System.out.println("proceducer "+id+" put "+buffer[(tail++)%buffer.length]);
				full.release();
				mutex.release();
			}
		}
	}
	class Consumer implements Runnable
	{
		int id;
		public Consumer(int id)
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
				if (mutex.tryAcquire())
				{
					if (full.tryAcquire())
					{
					}
					else
					{
						mutex.release();
						continue;
					}
				}
				else continue;
				System.out.println("consumer "+id+" get "+buffer[(head++)%buffer.length]);
				empty.release();
				mutex.release();
			}
		}
	}
	public static void main(String[] arg)
	{
		ProducerConsumerProblem producerConsumerProblem=new ProducerConsumerProblem(5);
		for (int i=0;i<5;i++) new Thread(producerConsumerProblem.new Proceducer(i)).start();
		for (int i=0;i<5;i++) new Thread(producerConsumerProblem.new Consumer(i)).start();
	}

}
