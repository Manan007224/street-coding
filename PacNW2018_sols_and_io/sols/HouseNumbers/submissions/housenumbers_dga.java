import java.io.PrintStream;
import java.util.Scanner;

/**
 * House Numbers
 * 
 * @author Dan Adkins
 */
public class housenumbers_dga
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        PrintStream ps = System.out;
        
	long m = sc.nextLong();
	long x = m + 1;
	long n = x + 1;
	long sum_left = m;
	long sum_right = n;

	while (sum_left != sum_right) {
	    if (sum_right < sum_left) {
		n++;
		sum_right += n;
	    } else { // sum_left < sum_right
		sum_left += x;
		x++;
		sum_right -= x;
	    }
	}
	
	ps.printf("%d %d %d\n", m, x, n);
    }
}
