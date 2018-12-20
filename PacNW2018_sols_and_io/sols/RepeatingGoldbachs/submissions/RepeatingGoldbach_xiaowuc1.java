import java.util.*;

public class RepeatingGoldbach_xiaowuc1 {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    boolean[] comp = new boolean[n];
    for(int i = 2; i * i < n; i++){
      if(comp[i]) continue;
      for(int j = i*i; j < n; j += i) {
        comp[j] = true;
      }
    }
    ArrayList<Integer> primes = new ArrayList<>();
    for(int i = 2; i < n; i++) {
      if(!comp[i]) {
        primes.add(i);
      }
    }
    int ret = 0;
    while(n > 2) {
      for(int out: primes) {
        if(!comp[n-out]) {
          n -= 2*out;
          ret++;
          break;
        }
      }
    }
    System.out.println(ret);
  }
}
