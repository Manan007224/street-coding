import java.util.*;

public class GoatRope_xiaowuc1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    int y = sc.nextInt();
    int x1 = sc.nextInt();
    int y1 = sc.nextInt();
    int x2 = sc.nextInt();
    int y2 = sc.nextInt();
    int dx = 0;
    if(x < x1) dx = Math.abs(x1-x);
    if(x > x2) dx = Math.abs(x2-x);
    int dy = 0;
    if(y < y1) dy = Math.abs(y1-y);
    if(y > y2) dy = Math.abs(y2-y);
    System.out.printf("%.3f\n", Math.hypot(dx, dy));
  }
}
