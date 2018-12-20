import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Liars
 * 
 * @author vanb
 */
public class truth_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    private void doit()
    {
        int n = sc.nextInt();
        int lo[] = new int[n];
        int hi[] = new int[n];
        
        for( int i=0; i<n; i++ )
        {
            lo[i] = sc.nextInt();
            hi[i] = sc.nextInt();
        }
        
		// The solution is the largest k for which exactly k intervals contain k
		// If there is no such k, then the answer is -1
        int solution = -1;
        for( int k=n; k>=0; k-- )
        {
            int count=0;
            for( int i=0; i<n; i++ ) if( lo[i]<=k && k<=hi[i] ) ++count;
            if( count==k )
            {
                solution = k;
                break;
            }
        }
        
        ps.println( solution );
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new truth_vanb().doit();
    }

}
