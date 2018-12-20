import java.io.*;
import java.util.*;

public class Exam_xiaowuc1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int k = Integer.parseInt(br.readLine());
    String a = br.readLine();
    String b = br.readLine();
    int n = a.length();
    int same = 0;
    int diff = 0;
    for(int i = 0; i < n; i++) {
      if(a.charAt(i) == b.charAt(i)) same++;
      else diff++;
    }
    int ret = -1;
    for(int x = 0; x <= same && x <= k; x++) {
      int theyAC = k-x;
      int theyWA = diff-theyAC;
      if(theyWA >= 0) {
        ret = Math.max(ret, x + theyWA);
      }
    }
    System.out.println(ret);
  }
}
