import java.util.*;

public class CountTheBits_xiaowuc1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int b = sc.nextInt();
    int inc = 1;
    final int MOD = 1000000009;
    int[][] dp = new int[k][b+1];
    dp[0][0] = 1;
    for(int qq = 0; qq < b; qq++) {
      int[][] ndp = new int[k][b+1];
      for(int i = 0; i < k; i++) {
        for(int j = 0; j < b; j++) {
          ndp[i][j] += dp[i][j];
          ndp[(i+inc)%k][j+1] += dp[i][j];
        }
      }
      for(int i = 0; i < k; i++) {
        for(int j = 0; j <= b; j++) {
          dp[i][j] = ndp[i][j]%MOD;
        }
      }
      inc *= 2;
      inc %= k;
    }
    long ret = 0;
    for(int a = 1; a <= b; a++) {
      ret += dp[0][a] * (long)a;
    }
    System.out.println(ret % MOD);
  }
}
