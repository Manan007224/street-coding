import java.io.*;
import java.util.*;

public class Rectangles_xiaowuc1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int[] x1 = new int[n];
    int[] y1 = new int[n];
    int[] x2 = new int[n];
    int[] y2 = new int[n];
    for(int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      x1[i] = Integer.parseInt(st.nextToken());
      y1[i] = Integer.parseInt(st.nextToken());
      x2[i] = Integer.parseInt(st.nextToken());
      y2[i] = Integer.parseInt(st.nextToken());
    }
    int[] allY = null;
    {
      TreeSet<Integer> ys = new TreeSet<>();
      for(int i = 0; i < n; i++) {
        ys.add(y1[i]);
        ys.add(y2[i]);
      }
      allY = new int[ys.size()];
      int idx = 0;
      for(int out: ys) {
        allY[idx++] = out;
      }
    }
    int[] yDiff = new int[allY.length-1];
    for(int i = 0; i < yDiff.length; i++) {
      yDiff[i] = allY[i+1] - allY[i];
    }
    RangeTree tree = new RangeTree(yDiff);
    Event[] events = new Event[2*n];
    for(int i = 0; i < n; i++) {
      events[2*i] = new Event(x1[i], y1[i], y2[i]);
      events[2*i+1] = new Event(x2[i], y1[i], y2[i]);
    }
    Arrays.sort(events);
    int lastX = 0;
    long ret = 0;
    for(Event out: events) {
      if(out.x != lastX) {
        ret += (out.x - lastX) * (long)tree.query(0, yDiff.length-1);
        lastX = out.x;
      }
      int low = Arrays.binarySearch(allY, out.y1);
      int high = Arrays.binarySearch(allY, out.y2)-1;
      tree.flip(low, high);
    }
    System.out.println(ret);
  }

  static class Event implements Comparable<Event> {
    public int x;
    public int y1, y2;
    public Event(int a, int b, int c) {
      x=a;
      y1=b;
      y2=c;
    }
    public int compareTo(Event e) {
      return x - e.x;
    }
  }

  static class RangeTree {
    int sz;
    int[] baseVal;
    int[] realVal;
    boolean[] flip;
    private void pushDown(int idx) {
      if(flip[idx]) {
        flip[2*idx] = !flip[2*idx];
        flip[2*idx+1] = !flip[2*idx+1];
        flip[idx] = false;
      }
    }
    private int eval(int idx) {
      if(flip[idx]) return baseVal[idx] - realVal[idx];
      return realVal[idx];
    }
    private void pullUp(int idx) {
      realVal[idx] = eval(2*idx) + eval(2*idx+1);
    }
    public RangeTree(int[] vals) {
      sz = vals.length;
      baseVal = new int[4*sz];
      realVal = new int[4*sz];
      flip = new boolean[4*sz];
      init(1, 0, sz-1, vals);
    }
    private void init(int idx, int l, int r, int[] v) {
      if(l == r) {
        baseVal[idx] = v[l];
      }
      else {
        int m = (l+r)/2;
        init(2*idx, l, m, v);
        init(2*idx+1, m+1, r, v);
        baseVal[idx] = baseVal[2*idx] + baseVal[2*idx+1];
      }
    }
    public void flip(int l, int r) {
      flip(1, 0, sz-1, l, r);
    }
    private void flip(int idx, int l, int r, int lhs, int rhs) {
      if(l >= lhs && r <= rhs) {
        flip[idx] = !flip[idx];
        return;
      }
      pushDown(idx);
      int m = (l+r)/2;
      if(m >= lhs) flip(2*idx, l, m, lhs, rhs);
      if(m+1 <= rhs) flip(2*idx+1, m+1, r, lhs, rhs);
      pullUp(idx);
    }
    public int query(int l, int r) {
      return query(1, 0, sz-1, l, r);
    }
    private int query(int idx, int l, int r, int lhs, int rhs) {
      if(l >= lhs && r <= rhs) {
        if(flip[idx]) return baseVal[idx] - realVal[idx];
        return realVal[idx];
      }
      pushDown(idx);
      int ret = 0;
      int m = (l+r)/2;
      if(m >= lhs) ret += query(2*idx, l, m, lhs, rhs);
      if(m+1 <= rhs) ret += query(2*idx+1, m+1, r, lhs, rhs);
      pullUp(idx);
      return ret;
    }
  }
}
