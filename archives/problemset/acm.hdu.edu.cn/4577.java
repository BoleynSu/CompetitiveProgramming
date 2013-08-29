import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

import javax.security.auth.x500.X500Principal;

public class Main {
    public static void main(String[] args) {
//        ft(n,1,1000)
//            ft(k,2,10)
//            {
//                int ans=0;
//                for (int i=1;i<=n;i+=2)
//                {
//                    int x=floor(log(n/i)/log(2))+1;
//                    ans+=x/k;
//                }
//                cerr<<ans<<char(k==10?'\n':' ');
//            }
//        rtn 0;
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int T = in.nextInt();
        for (int t=0;t<T;t++)
        {
            BigInteger n = in.nextBigInteger();
            int k = in.nextInt();
            BigInteger ans = BigInteger.ZERO;
            //n/2^x<i<=n/2^(x-1)
            BigInteger beg=n.shiftRight(k-1),end=n;
            int x=0;
            while (beg.compareTo(end)!=0)
            {
                //System.out.println(beg+" "+end);
                int delta=(end.testBit(0)?1:0)-(beg.testBit(0)?1:0);
                ans=ans.add(BigInteger.valueOf(x).multiply(end.shiftRight(1).subtract(beg.shiftRight(1)).add(BigInteger.valueOf(delta))));
                end = beg;
                beg = beg.shiftRight(k);
                x++;
            }
            System.out.println(ans);
        }
    }
}
