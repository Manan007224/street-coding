import java.io.*;
import java.util.*;

public class CopsAndRobbers_xiaowuc1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int m = Integer.parseInt(st.nextToken());
    int n = Integer.parseInt(st.nextToken());
    int c = Integer.parseInt(st.nextToken());
    char[][] grid = new char[n][];
    for(int i = 0; i < n; i++) {
      grid[i] = br.readLine().toCharArray();
    }
    /*
    construction
    0 to n*m-1 are start vertices per square
    n*m to 2*n*m-1 are end vertices per square
    2*n*m is source
    2*n*m+1 is sink
    start to end is infinity when square is not blocked
    start to end is cost of unblocking otherwise
    end to start for adjacent
    end to sink for those outside
    source to starting
    */
    long[] costs = new long[c];
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < c; i++) {
      costs[i] = Long.parseLong(st.nextToken());
    }
    g = new long[2*n*m+2][2*n*m+2];
    int[] dx = new int[]{-1,1,0,0};
    int[] dy = new int[]{0,0,-1,1};
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(grid[i][j] == 'B') {
          g[2*m*n][i*m+j] = INF;
        }
        if(grid[i][j] >= 'a' && grid[i][j] <= 'z') {
          g[i*m+j][i*m+j+m*n] = costs[grid[i][j]-'a'];
        }
        else {
          g[i*m+j][i*m+j+m*n] = INF;
        }
        if(i == 0 || i == n-1 || j == 0 || j == m-1) {
          g[i*m+j+m*n][2*m*n+1] = INF;
        }
        for(int k = 0; k < dx.length; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
            g[i*m+j+n*m][nx*m+ny] = INF;
          }
        }
      }
    }
    long ret = getFlow(2*n*m, 2*n*m+1);
    if(ret >= INF) ret = -1;
    System.out.println(ret);
  }

  static final long INF = 1L << 40;
  static long[][] g;
  public static long getFlow(int s, int t) {
    long ret = 0;
    int[] par = new int[g.length];
    long[] dp = new long[g.length];
    while(ret < INF) {
      Arrays.fill(par, -1);
      Arrays.fill(dp, 0);
      par[s] = -2;
      dp[s] = INF;
      LinkedList<Integer> q = new LinkedList<>();
      q.add(s);
      while(!q.isEmpty() && dp[t] == 0) {
        int curr = q.removeFirst();
        for(int i = 0; i < g.length; i++) {
          if(par[i] == -1 && g[curr][i] > 0) {
            dp[i] = Math.min(dp[curr], g[curr][i]);
            par[i] = curr;
            q.add(i);
          }
        }
      }
      if(dp[t] == 0) break;
      ret += dp[t];
      int curr = t;
      while(curr != s) {
        g[par[curr]][curr] -= dp[t];
        g[curr][par[curr]] += dp[t];
        curr = par[curr];
      }
    }
    return ret;
  }

}
