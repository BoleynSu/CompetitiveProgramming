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
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
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
				buffer[(tail++)%buffer.length]=id;
				System.out.println("proceducer "+id);
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
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
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
		ProducerConsumerProblem producerConsumerProblem=new ProducerConsumerProblem(10);
		for (int i=0;i<5;i++) new Thread(producerConsumerProblem.new Proceducer(i)).start();
		for (int i=0;i<5;i++) new Thread(producerConsumerProblem.new Consumer(i)).start();
	}

}
