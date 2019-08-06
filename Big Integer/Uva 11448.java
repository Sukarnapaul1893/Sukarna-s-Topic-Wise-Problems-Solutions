import java.math.*;
import java.util.*;

public class Main{
    public static void main(String[] args){
        BigInteger a,b;
        Scanner src = new Scanner(System.in);
        int t;
        t = src.nextInt();
        while(t>0){
            t--;
            a = src.nextBigInteger();
            b = src.nextBigInteger();
            System.out.println(a.subtract(b));
        }
    }
}
