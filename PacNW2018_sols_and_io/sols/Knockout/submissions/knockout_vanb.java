import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Knockout
 * 
 * @author vanb
 */
public class knockout_vanb
{
    
    /** Input. */
    private static Scanner sc;
    
    /** Output. */
    private static PrintStream ps;
    
    /**
     * Convert digits to an integer.
     *
     * @param digits the digits
     * @return the integer
     */
    private int digitize( boolean digits[] )
    {
        int total = 0;
        for( int i=0; i<digits.length; i++ ) if( digits[i] )
        {
            total *= 10;
            total += i;
        }
        
        return total;
    }
    
    /** The probabilities of each roll, 2 to 12. */
    private double probs[] =
    {
        /*  0 */ 0.0, 
        /*  1 */ 0.0, 
        /*  2 */ 1.0/36.0, 
        /*  3 */ 2.0/36.0, 
        /*  4 */ 3.0/36.0, 
        /*  5 */ 4.0/36.0, 
        /*  6 */ 5.0/36.0, 
        /*  7 */ 6.0/36.0, 
        /*  8 */ 5.0/36.0, 
        /*  9 */ 4.0/36.0, 
        /* 10 */ 3.0/36.0, 
        /* 11 */ 2.0/36.0, 
        /* 12 */ 1.0/36.0  
    };
    
    /** The ways of summing digits to a given roll. */
    private int sums[][][] =
    {
        /*  0 */ {{}},
        /*  1 */ {{}},
        /*  2 */ {{2}},
        /*  3 */ {{3},{1,2}},
        /*  4 */ {{4},{1,3}},
        /*  5 */ {{5},{1,4},{2,3}},
        /*  6 */ {{6},{1,5},{2,4},{1,2,3}},
        /*  7 */ {{7},{1,6},{2,5},{3,4},{1,2,4}},
        /*  8 */ {{8},{1,7},{2,6},{3,5},{1,2,5},{1,3,4}},
        /*  9 */ {{9},{1,8},{2,7},{3,6},{4,5},{1,2,6},{1,3,5},{2,3,4}},
        /* 10 */ {{1,9},{2,8},{3,7},{4,6},{1,2,7},{1,3,6},{1,4,5},{2,3,5},{1,2,3,4}},
        /* 11 */ {{2,9},{3,8},{4,7},{5,6},{1,2,8},{1,3,7},{1,4,6},{2,3,6},{2,4,5},{1,2,3,5}},
        /* 12 */ {{3,9},{4,8},{5,7},{1,2,9},{1,3,8},{1,4,7},{1,5,6},{2,3,7},{2,4,6},{3,4,5},{1,2,3,6},{1,2,4,5}}        
    };
    
    /** The digits. */
    private boolean digits[] = new boolean[10];
    
    /** Maximize (true) or Minimize (false)? */
    private boolean maximize;
    
    /** The digits taken. */
    private String taken;
    
    /**
     * Play a turn.
     *
     * @param roll the roll
     * @param top at the top level?
     * @return the average result
     */
    private double play( int roll, boolean top )
    {
        // We need an extreme, out-of-range value to start with.
        // That's different whether we're maximizing or minimizing
        double best = maximize ? -1.0 : 10000000000.0;
        
        // Go through all digit combinations possible for this roll
        for( int takes[] : sums[roll]  )
        {
            // Are all of the digits available?
            boolean cando = true;
            for( int take : takes ) if( !digits[take] ) cando = false;
            if( cando )
            {
                // Keep playing another round
                double result = 0.0;
                for( int take : takes ) digits[take] = false; 
                for( int r=2; r<=12; r++ ) result += probs[r]*play(r,false);
                for( int take : takes ) digits[take] = true; 
                
                // Is this better than anything we've seen so far?
                if( maximize ? result>best : result<best ) 
                {
                    best = result;                        
                    
                    // We're only interested in saving the digits taken at the top level 
                    if( top ) 
                    {
                        taken = "";
                        for( int take : takes ) taken += (char)(take+'0');                         
                    }
                }
            }
        }
        
        // If best is out of range, that means we couldn't play any combo of digits.
        // So, the result is just the digits we've got.
        return best<0.0 || best>9999999999.0 ? digitize( digits ) : best ;
    }
    
    /**
     * Solve.
     *
     * @param remaining the remaining digits
     * @param roll the roll
     * @param max Maximize (true) or Minimize (false)
     */
    private void solve( char remaining[], int roll, boolean max )
    {
        maximize = max;
        Arrays.fill( digits, false );
        for( char digit : remaining ) digits[(int)(digit-'0')] = true;
        taken = "-1";
        
        double best = play( roll, true );
        
        ps.printf( "%s %.5f", taken, best );
        ps.println();
    }
    
    /**
     * Do it.
     */
    private void doit()
    {
        char remaining[] = sc.next().toCharArray();
        int roll = sc.nextInt() + sc.nextInt();
        
        // Maximize
        solve( remaining, roll, false );
        
        // Minimize
        solve( remaining, roll, true );
    }
        
    /**
     * The main method.
     *
     * @param args the arguments
     * @throws Exception the exception
     */
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new knockout_vanb().doit();
    }

}
