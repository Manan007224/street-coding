import java.util.*;

public class PokerHand_xiaowuc1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int[] dp = new int[256];
    int ret = 0;
    for(int i = 0; i < 5; i++) {
      ret = Math.max(ret, ++dp[sc.next().charAt(0)]);
    }
    System.out.println(ret);
  }
}
