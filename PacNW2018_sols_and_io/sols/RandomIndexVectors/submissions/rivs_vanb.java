import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 * Solution to Random Index Vectors
 * 
 * @author vanb
 */
public class rivs_vanb
{
    
    /** Input. */
    private static Scanner sc;
    
    /** Output. */
    private static PrintStream ps;
    
    /**
     * Read a vector.
     *
     * @return the long[]
     */
    private long[] readVector()
    {
        int m = sc.nextInt();
        long v[] = new long[m];
        for( int i=0; i<m; i++ ) v[i] = sc.nextLong();
        
        return v;
    }
    
    /** The length of the vectors. */
    private long n;
    
    /** The number of indices to rotate by. */
    private long k;
        
    /**
     * Rotate a vector.
     *
     * @param v the vector
     */
    private void rotate( long v[] )
    {
        // Find the breakpoint b where |v[i]|<=k for i<=b, |v[i]|>k for i>b
        int b=0;
        for( ; b<v.length && Math.abs( v[b] )<=k; ++b );
        
        // We'll create a new vector
        long newv[] = new long[v.length];
        
        // Start with those at the end that get moved to the beginning
        int i=0;
        for( int j=b; j<v.length; j++ ) 
        {
            newv[i] = Math.abs(v[j]) - k;
            if( v[j]<0 ) newv[i] = -newv[i];
            ++i;
        }
        
        // Now, those at the beginning that get moved to the end 
        for( int j=0; j<b; j++ ) 
        {
            newv[i] = Math.abs(v[j]) + n - k;
            if( v[j]<0 ) newv[i] = -newv[i];
            ++i;
        }
        
        // Print the result
        ps.print( newv.length );
        for( long index : newv ) ps.print( " " + index );
        ps.println();
    }
    
    /**
     * Print a vector in condensed form.
     *
     * @param v the vector
     */
    private void print( List<Long> v )
    {
        ps.print( v.size() );
        for( Long x : v ) ps.print( " " + x );
        ps.println();
    }
    
    /**
     * Do it.
     */
    private void doit()
    {
        n = sc.nextLong();
        k = sc.nextLong();
        
        long[] v1 = readVector();
        long[] v2 = readVector();
        
        ArrayList<Long> result = new ArrayList<Long>(v1.length+v2.length);
        
        // Sum
        int i=0, j=0;
        while( i<v1.length && j<v2.length )
        {
            if( v1[i]==v2[j] )
            {
                // 1 + 1 = 1, -1 + -1 = -1
                result.add( v1[i++] );
                ++j;
            }
            else if( Math.abs( v1[i] ) < Math.abs( v2[j] ) )
            {
                // 1 + 0 = 1, -1 + 0 = -1
                result.add( v1[i++] );                
            }
            else if( Math.abs( v1[i] ) > Math.abs( v2[j] ) )
            {
                // 0 + 1 = 1, 0 + -1 = -1
                result.add( v2[j++] );                
            }
            else 
            {
                // 1 + -1 = 0, -1 + 1 = 0
                ++i; ++j;
            }
        }

        // Only one of these will be true
        while( i<v1.length ) result.add( v1[i++] ); 
        while( j<v2.length ) result.add( v2[j++] ); 
        
        print( result );
        
        // Product
        i=0;
        j=0;
        result.clear();
        while( i<v1.length && j<v2.length )
        {
            if( Math.abs(v1[i])==Math.abs(v2[j]) )
            {
                // 1 * 1 = 1, -1 * -1 = 1, 1 * -1 = -1, -1 * 1 = -1
                result.add( v1[i]==v2[j] ? Math.abs( v1[i] ) : -Math.abs( v1[i] ) );
                ++i;
                ++j;
            }
            else if( Math.abs( v1[i] ) < Math.abs( v2[j] ) )
            {
                // 1 * 0 = 0, -1 * 0 = 0
                ++i;
            }
            else 
            {
                // 0 * 1 = 0, 0 * -1 = 0
                ++j;
            }
        }
        print( result );
        
        // Rotations
        rotate( v1 );
        rotate( v2 );
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
        
        new rivs_vanb().doit();
    }

}
