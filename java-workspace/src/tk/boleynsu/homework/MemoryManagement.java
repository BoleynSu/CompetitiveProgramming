package tk.boleynsu.homework;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.TreeSet;

abstract class Algorithm {
	private static final int MEMERY_SIZE = 1 << 15;
	private int hit = 0, total = 0;
	private int pageSize;
	private Set<Integer> memery = new TreeSet<Integer>();

	public Algorithm(int pageSize) {
		this.pageSize = pageSize;
	}

	public void access(int address) {
		total++;
		if (memery.contains(address / pageSize)) {
			hit++;
			hitPage(address / pageSize);
		} else {
			memery.remove(getRemovingPage());
			memery.add(address / pageSize);
			loadPage(address / pageSize);
		}
	}

	public double getHitRate() {
		return (double) hit / total;
	}

	public int getMaxPageNumber() {
		return MEMERY_SIZE / pageSize;
	}

	abstract public Integer getRemovingPage();

	abstract public void hitPage(int page);

	abstract public void loadPage(int page);
}

class FIFOAlgorithm extends Algorithm {
	Queue<Integer> fifo = new LinkedList<Integer>();

	public FIFOAlgorithm(int pageSize) {
		super(pageSize);
	}

	@Override
	public Integer getRemovingPage() {
		if (fifo.size() < getMaxPageNumber()) {
			return null;
		} else {
			return fifo.remove();
		}
	}

	@Override
	public void hitPage(int page) {

	}

	@Override
	public void loadPage(int page) {
		fifo.add(page);
	}
}

public class MemoryManagement {

	public static void main(String[] args) {

	}

}
