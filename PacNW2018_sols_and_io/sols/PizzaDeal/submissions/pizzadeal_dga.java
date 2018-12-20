import java.io.PrintStream;
import java.util.Scanner;

/**
 * Pizza Deal
 * 
 * @author Dan Adkins
 */
public class pizzadeal_dga
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        PrintStream ps = System.out;
        
	double a1 = sc.nextDouble();
	double p1 = sc.nextDouble();
	double r2 = sc.nextDouble();
	double p2 = sc.nextDouble();
	double a2 = Math.PI * r2 * r2;

	if (a1/p1 > a2/p2)
	    ps.printf("Slice of pizza\n");
	else
	    ps.printf("Whole pizza\n");
    }
}
