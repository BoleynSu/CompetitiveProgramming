package tk.boleynsu.homework;

import java.io.IOException;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

abstract class Algorithm {
	protected final int PAGE_AMOUNT, PAGE_SIZE;
	protected int hit = 0, total = 0;
	protected Set<Integer> memery = new TreeSet<Integer>();

	public Algorithm(int PAGE_AMOUNT, int PAGE_SIZE) {
		this.PAGE_AMOUNT = PAGE_AMOUNT;
		this.PAGE_SIZE = PAGE_SIZE;
	}

	public void access(int address) {
		total++;
		if (memery.contains(address / PAGE_SIZE)) {
			hit++;
			hitPage(address / PAGE_SIZE);
		} else {
			if (memery.size() == PAGE_AMOUNT)
			{
				memery.remove(getRemovingPage());
			}
			memery.add(address / PAGE_SIZE);
			loadPage(address / PAGE_SIZE);
		}
	}

	public void print() {
		if (this instanceof FIFOAlgorithm)
		{
			System.out.print("FIFO");
		}
		else if (this instanceof OPTAlgorithm)
		{
			System.out.print("OPT");
		}
		else if (this instanceof LRUAlgorithm)
		{
			System.out.print("LRU");
		}
		System.out.println("算法：每页大小为" + (PAGE_SIZE >> 10) + "KB，共" + PAGE_AMOUNT + "页时的命中率为：" + (double)hit / total);
	}

	abstract public Integer getRemovingPage();

	abstract public void hitPage(int page);

	abstract public void loadPage(int page);
}

class FIFOAlgorithm extends Algorithm {
	Queue<Integer> fifo = new LinkedList<Integer>();

	public FIFOAlgorithm(int PAGE_AMOUNT, int PAGE_SIZE) {
		super(PAGE_AMOUNT, PAGE_SIZE);
	}

	@Override
	public Integer getRemovingPage() {
		return fifo.remove();
	}

	@Override
	public void hitPage(int page) {

	}

	@Override
	public void loadPage(int page) {
		fifo.add(page);
	}
}

class OPTAlgorithm extends Algorithm {

	protected int[] address;
	
	public OPTAlgorithm(int PAGE_AMOUNT, int PAGE_SIZE, int[] address) {
		super(PAGE_AMOUNT, PAGE_SIZE);
		this.address = address;
	}

	@Override
	public Integer getRemovingPage() {
		Set<Integer> rest = new TreeSet<Integer>();
		rest.addAll(memery);
		for (int i = total; rest.size()!=1 && i < address.length; i++)
			if (rest.contains(address[i] / PAGE_SIZE))
			{
				rest.remove(address[i] / PAGE_SIZE);
			}
		return rest.iterator().next();
	}

	@Override
	public void hitPage(int page) {

	}

	@Override
	public void loadPage(int page) {
	}

}

class LRUAlgorithm extends Algorithm {
	
	class Item implements Comparable<Item> {

		private int time, page;
		public Item(int time, int page) {
			this.time = time;
			this.page = page;
		}
		@Override
		public int compareTo(Item o) {
			return time - o.time;
		}
		public int getPage() {
			return page;
		}
	}
	
	Set<Item> lru = new TreeSet<Item>();
	Map<Integer, Integer> time = new TreeMap<Integer, Integer>();

	public LRUAlgorithm(int PAGE_AMOUNT, int PAGE_SIZE) {
		super(PAGE_AMOUNT, PAGE_SIZE);
	}

	@Override
	public Integer getRemovingPage() {
		int page = lru.iterator().next().getPage();
		lru.remove(new Item(time.get(page),page));
		return page;
	}

	@Override
	public void hitPage(int page) {
		lru.remove(new Item(time.remove(page), page));
		time.put(page, total);
		lru.add(new Item(total, page));
	}

	@Override
	public void loadPage(int page) {
		time.put(page, total);
		lru.add(new Item(total, page));
	}
	
}

public class MemoryManagement {

	public static void main(String[] args) throws IOException {
		
		Algorithm algorithm;
		int[] address = new int[1<<8];
		for (int i = 0; i < address.length/2; i++)
			address[i]=i==0?(int) (Math.random()*(1 << 15)/2):address[i-1]+1;
		for (int i = address.length / 2; i < address.length * 3 / 4; i++)
			address[i]=(int) (Math.random()*(1 << 15)/2);
		for (int i = address.length * 3 / 4; i < address.length; i++)
			address[i]=(int) (Math.random()*(1 << 15)/2)+(1 << 15)/2;

		System.out.println("地址流：");
		for (int i = 0; i < address.length; i++)
		{
			System.out.print(address[i]+",");
			if (i%8==7) System.out.println();
		}
		for (int j = (1 << 10); j <= (1 << 13); j <<= 1)
		{
			for (int i = (1 << 2); i*j <= (1 << 15); i <<= 1)
			{
				algorithm=new FIFOAlgorithm(i, j);
				for (int p : address)
					algorithm.access(p);
				algorithm.print();
			}
		}
		for (int j = (1 << 10); j <= (1 << 13); j <<= 1)
		{
			for (int i = (1 << 2); i*j <= (1 << 15); i <<= 1)
			{
				algorithm=new OPTAlgorithm(i, j, address);
				for (int p : address)
					algorithm.access(p);
				algorithm.print();
			}
		}
		for (int j = (1 << 10); j <= (1 << 13); j <<= 1)
		{
			for (int i = (1 << 2); i*j <= (1 << 15); i <<= 1)
			{
				algorithm=new LRUAlgorithm(i, j);
				for (int p : address)
					algorithm.access(p);
				algorithm.print();
			}
		}
	}

}
