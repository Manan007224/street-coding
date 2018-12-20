import java.util.*;

public class RandomIndexVectors_xiaowuc1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    long k = sc.nextLong();
    RIV r1 = load(n, sc);
    RIV r2 = load(n, sc);
    System.out.println(r1.add(r2));
    System.out.println(r1.multiply(r2));
    System.out.println(r1.rotate(k));
    System.out.println(r2.rotate(k));
  }

  public static RIV load(long sz, Scanner sc) {
    int n = sc.nextInt();
    ArrayList<Long> ret = new ArrayList<>();
    while(n-- > 0) {
      ret.add(sc.nextLong());
    }
    return new RIV(sz, ret);
  }

  static class RIV {
    Map<Long, Integer> dp;
    long sz;
    public String toString() {
      StringBuilder sb = new StringBuilder();
      sb.append(dp.size());
      for(long out: dp.keySet()) {
        sb.append(" ");
        sb.append(out * dp.get(out));
      }
      return sb.toString();
    }
    public RIV(long n, Map<Long, Integer> in) {
      dp = in;
      sz = n;
    }
    public RIV(long n, ArrayList<Long> l) {
      sz = n;
      dp = new TreeMap<>();
      for(long out: l) {
        if(out > 0) {
          dp.put(out, 1);
        }
        else {
          dp.put(-out, -1);
        }
      }
    }
    public RIV rotate(long k) {
      Map<Long, Integer> now = new TreeMap<>();
      for(long out: dp.keySet()) {
        long nv = (out+sz-k)%sz;
        if(nv == 0) nv = sz;
        now.put(nv, dp.get(out));
      }
      return new RIV(sz, now);
    }
    public RIV add(RIV x) {
      Map<Long, Integer> now = new TreeMap<>();
      for(long out: dp.keySet()) {
        update(now, out, dp.get(out));
      }
      for(long out: x.dp.keySet()) {
        update(now, out, x.dp.get(out));
      }
      return new RIV(sz, now);
    }
    public RIV multiply(RIV x) {
      Map<Long, Integer> now = new TreeMap<>();
      for(long out: dp.keySet()) {
        if(x.dp.containsKey(out)) {
          now.put(out, dp.get(out) * x.dp.get(out));
        }
      }
      return new RIV(sz, now);
    }
  }
  public static void update(Map<Long, Integer> m, long k, int v) {
    int nv = m.getOrDefault(k, 0) + v;
    if(nv > 1) nv = 1;
    if(nv < -1) nv = -1;
    if(nv == 0) {
      m.remove(k);
    }
    else {
      m.put(k, nv);
    }
  }
}
