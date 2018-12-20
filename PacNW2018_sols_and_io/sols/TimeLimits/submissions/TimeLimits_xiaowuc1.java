import java.util.*;

public class TimeLimits_xiaowuc1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long scale = sc.nextInt();
    long ret = 0;
    while(n-- > 0) {
      ret = Math.max(ret, scale * sc.nextInt());
    }
    System.out.println((ret+999)/1000);
  }
}
