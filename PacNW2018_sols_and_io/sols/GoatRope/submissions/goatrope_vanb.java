import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Goat Rope
 * 
 * @author vanb
 */
public class goatrope_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    private void doit()
    {
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        double x1 = sc.nextDouble();
        double y1 = sc.nextDouble();
        double x2 = sc.nextDouble();
        double y2 = sc.nextDouble();
        
        double max = Double.MAX_VALUE;
        
        max = Math.min( max, Math.hypot( x-x1, y-y1 ) );
        max = Math.min( max, Math.hypot( x-x1, y-y2 ) );
        max = Math.min( max, Math.hypot( x-x2, y-y1 ) );
        max = Math.min( max, Math.hypot( x-x2, y-y2 ) );
        
        if( x1<=x && x<=x2 ) max = Math.min( max, Math.min( Math.abs( y-y1 ), Math.abs( y-y2 ) ) );
        if( y1<=y && y<=y2 ) max = Math.min( max, Math.min( Math.abs( x-x1 ), Math.abs( x-x2 ) ) );
        
        ps.printf( "%.3f", max );
        ps.println();        
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new goatrope_vanb().doit();
    }

}
