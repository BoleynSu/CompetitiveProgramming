import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;


public class TestException3 {
	public static void cat(File file) throws IOException {

		RandomAccessFile input = null;

		String line = null;

		try {

		input = new RandomAccessFile(file, "r");

		while ((line = input.readLine()) != null) {

		System.out.println(line);

		}

		return;

		} finally {

		if (input != null) {

		input.close();

		}

		}

		}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
