import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Time Limits
 * 
 * @author vanb
 */
public class timelimits_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    private void doit()
    {
        int n = sc.nextInt();
        int s = sc.nextInt();
        
        // Find the slowest solution
        int slowest = 0;
        for( int i=0; i<n; i++ )
        {
            int m = sc.nextInt();
            if( m>slowest ) slowest = m;
        }
        
        // Number of milliseconds to let a submission run
        int milliseconds = s*slowest;
        
        // Number of seconds
        int seconds = milliseconds/1000;
        
        // if there's any remainder, we need another second
        if( milliseconds%1000>0 ) ++seconds;
        
        ps.println( seconds );
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new timelimits_vanb().doit();
    }

}
