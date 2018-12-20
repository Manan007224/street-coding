import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Exam
 * 
 * @author vanb
 */
public class exam_vanb
{
    
    /** Input. */
    private static Scanner sc;
    
    /** Output. */
    private static PrintStream ps;
    
    /**
     * Do it.
     */
    private void doit()
    {
        int right = sc.nextInt();
        char a[] = sc.next().toCharArray();
        char b[] = sc.next().toCharArray();
        int wrong = a.length-right;
        
        int match = 0;
        for( int i=0; i<a.length; i++ ) if( a[i]==b[i] ) ++match;      
        int mismatch = a.length-match;
        
        ps.println( Math.min( match, right ) + Math.min( mismatch, wrong ) );        
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
        
        new exam_vanb().doit();
    }

}
