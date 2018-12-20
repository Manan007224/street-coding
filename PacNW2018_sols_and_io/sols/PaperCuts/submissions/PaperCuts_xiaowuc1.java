import java.util.*;

public class PaperCuts_xiaowuc1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String a = sc.next();
    String b = sc.next();
    int[] dp = new int[1 << a.length()];
    Arrays.fill(dp, 1 << 25);
    dp[0] = 0;
    for(int mask = 0; mask < dp.length; mask++) {
      int start = Integer.bitCount(mask);
      for(int len = 1; start + len <= a.length(); len++) {
        int val = (1<<len)-1;
        int check = 0;
        boolean found = false;
        while(val < dp.length) {
          if((mask&val) == 0 && a.substring(start, start+len).equals(b.substring(check, check+len))) {
            dp[mask | val] = Math.min(dp[mask | val], dp[mask] + 1);
            found = true;
          }
          val <<= 1;
          check++;
        }
        if(!found) {
          break;
        }
      }
    }
    System.out.println(dp[dp.length-1]-1);
  }
}
