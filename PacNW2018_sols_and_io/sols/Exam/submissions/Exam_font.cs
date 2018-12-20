using System;

class Exam_font
{
	static void Main() 
	{
      int n = Convert.ToInt32(Console.ReadLine());
      string yourAnswers = Console.ReadLine();
      string friendsAnswers = Console.ReadLine();
	
      int numDifferent = 0;
      int numSame = 0;
      for (int i=0; i<yourAnswers.Length; i++)
      {
         if (yourAnswers[i] != friendsAnswers[i])
         {
            numDifferent++;
         }
         else
         {
            numSame++;
         }
      }

      int yourScore = Math.Min(n, numSame) 
         + Math.Min(numDifferent, numSame+numDifferent-n);
      Console.WriteLine(yourScore);
   }
}
