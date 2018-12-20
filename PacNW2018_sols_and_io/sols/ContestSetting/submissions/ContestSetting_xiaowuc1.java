import java.io.*;
import java.util.*;

public class ContestSetting_xiaowuc1 {
  static final int MOD = 998244353;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    int[] l = new int[n];
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < n; i++) {
      l[i] = Integer.parseInt(st.nextToken());
    }
    Arrays.sort(l);
    long[] dp = new long[k+1];
    dp[0] = 1;
    for(int i = 0; i < n;) {
      int j = i+1;
      while(j < n && l[i] == l[j]) j++;
      int freq = j-i;
      long[] ndp = new long[k+1];
      for(int a = 0; a <= k; a++) {
        ndp[a] += dp[a];
        if(a > 0) {
          ndp[a] += freq * dp[a-1];
        }
        ndp[a] %= MOD;
      }
      dp = ndp;
      i=j;
    }
    System.out.println(dp[k]);
  }
}
