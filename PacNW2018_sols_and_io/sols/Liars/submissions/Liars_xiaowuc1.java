import java.util.*;

public class Liars_xiaowuc1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] dp = new int[n+2];
    for(int i = 0; i < n; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      dp[a]++;
      dp[b+1]--;
    }
    for(int i = 1; i < dp.length; i++) {
      dp[i] += dp[i-1];
    }
    int ret = -1;
    for(int i = n; ret < 0 && i >= 0; i--) {
      if(dp[i] == i) {
        ret = i;
      }
    }
    System.out.println(ret);
  }
}
