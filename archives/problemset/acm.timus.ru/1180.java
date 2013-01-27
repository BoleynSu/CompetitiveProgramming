import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
static public void main(String[] arg)
{
Scanner cin=new Scanner(new BufferedInputStream(System.in));
int a=cin.nextBigInteger().mod(BigInteger.valueOf(3)).intValue();
if (a!=0) System.out.printf("%d%n%d%n",1,a);
else System.out.printf("2%n");
}
}