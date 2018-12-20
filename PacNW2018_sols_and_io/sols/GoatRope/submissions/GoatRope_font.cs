using System;

class GoatRope_font
{
   static double mag(double x, double y)
   {
      return Math.Sqrt(x*x+y*y);
   }

	static void Main() 
	{
      string input = Console.ReadLine();
      string[] tokens = input.Split(' ');

      int x = Convert.ToInt32(tokens[0]);
      int y = Convert.ToInt32(tokens[1]);
      int x1 = Convert.ToInt32(tokens[2]);
      int y1 = Convert.ToInt32(tokens[3]);
      int x2 = Convert.ToInt32(tokens[4]);
      int y2 = Convert.ToInt32(tokens[5]);

      double xx = Math.Max(Math.Max(x1-x, x-x2), 0);
      double yy = Math.Max(Math.Max(y1-y, y-y2), 0);
      double result = mag(xx, yy);

      string output = String.Format("{0:F3}", result);
      Console.WriteLine(output);
	}
}
