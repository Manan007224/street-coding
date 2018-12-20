import java.util.*;
public class CoprimeIntegers_xiaowuc1 {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int a = scan.nextInt();
    int b = scan.nextInt();
    int c = scan.nextInt();
    int d = scan.nextInt();
    init(Math.min(b, d));
    System.out.println(solve(b, d) - solve(a-1, d) - solve(b, c-1) + solve(a-1, c-1));
  }
  static int[] p;
  static boolean[] bad;
  public static long solve(long a, long b) {
    long ret = a*b;
    for(int i = 2; i <= Math.min(a, b); i++) {
      if(bad[i]) continue;
      long val = (a/i)*(b/i);
      if(p[i]%2 != 0) ret -= val;
      else ret += val;
    }
    return ret;
  }

  public static void init(int maxV) {
    p = new int[maxV+1];
    bad = new boolean[maxV+1];
    for(int i = 2; i <= maxV; i++) {
      if(p[i] != 0) continue;
      for(int j = i; j <= maxV; j += i) {
        p[j]++;
      }
      if(i*(long)i <= maxV)
      for(int j = i*i; j <= maxV; j += i*i) {
        bad[j] = true;
      }
    }
  }
}
