import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Repeating Goldbachs
 * 
 * @author vanb
 */
public class goldbach_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    private void doit()
    {
        // Start with a simple sieve of Eratosthenes
        boolean isPrime[] = new boolean[1000001];
        Arrays.fill( isPrime, true );
        isPrime[0] = isPrime[1] = false;
        for( int i=2; i<isPrime.length; i++ ) if( isPrime[i] )
        {
            for( int j=i+i; j<isPrime.length; j+=i ) isPrime[j] = false;
        }
        
        int n = sc.nextInt();
        int count = 0;
        while( n>3 )
        {
            int i;
            for( i=2; i<isPrime.length; i++ ) if( isPrime[i] && isPrime[n-i] ) break;
            n -= i+i;
            ++count;
        }
        ps.println( count );
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new goldbach_vanb().doit();
    }

}
