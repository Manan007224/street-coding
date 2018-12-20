import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Inversions_lewin {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Inversions solver = new Inversions();
        solver.solve(1, in, out);
        out.close();
    }

    static class Inversions {
        int n;
        int k;
        int[] arr;
        int[][] counts_pre;
        int[][] counts_suf;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            arr = in.readIntArray(n);
            counts_pre = new int[k + 2][n + 2];
            counts_suf = new int[k + 2][n + 2];

            for (int j = 0; j <= k; j++) {
                for (int i = 1; i <= n; i++) {
                    counts_pre[j][i] = counts_pre[j][i - 1];
                    if (arr[i - 1] == j) counts_pre[j][i]++;
                }
            }
            for (int j = k; j >= 1; j--) {
                for (int i = 1; i <= n; i++) {
                    counts_pre[j][i] += counts_pre[j + 1][i];
                }
            }
            for (int i = n; i >= 1; i--) {
                for (int j = 1; j <= k; j++) counts_suf[j][i] = counts_suf[j][i + 1];
                if (arr[i - 1] != 0) counts_suf[arr[i - 1]][i]++;
            }
            for (int j = 1; j <= k; j++) {
                for (int i = 1; i <= n; i++) {
                    counts_suf[j][i] += counts_suf[j - 1][i];
                }
            }


            long current = 0;
            for (int i = 1; i <= n; i++) {
                if (arr[i - 1] != 0) {
                    current += counts_pre[arr[i - 1] + 1][i - 1];
                }
            }

            long[] dp = new long[n + 1];
            Arrays.fill(dp, -(1L << 60));
            dp[0] = 0;

            long[] psum = new long[n + 2];
            long[] cc = new long[n + 2];
            for (int i = 1; i <= n; i++) cc[i] = 1L * counts_pre[0][i] * counts_pre[0][i];
            for (int cnum = k; cnum >= 1; cnum--) {
                LiChaoNode rt = new LiChaoNode(0, counts_pre[0][n], null);
                rt.insert(new LiChaoNode.Line(0, 0));

                for (int i = 1; i <= n; i++) {
                    psum[i] = psum[i - 1];
                    if (arr[i - 1] == 0) {
                        psum[i] += counts_pre[cnum + 1][i] + counts_suf[cnum - 1][i];
//                    ndp[i] = dp[i];
//                    for (int j = i; j >= 1; j--) {
//                        ndp[i] = Math.max(ndp[i], dp[j-1] + psum[i] - psum[j-1] + 1L * (counts_pre[0][j-1]) * (counts_pre[0][i] - counts_pre[0][j-1]));
//                    }
                        rt.insert(new LiChaoNode.Line(-counts_pre[0][i], cc[i] + psum[i] - dp[i]));
                        dp[i] = -rt.query(counts_pre[0][i]) + psum[i];
                    } else {
                        dp[i] = dp[i - 1];
                    }
                }
            }
            out.println(current + dp[n]);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static class LiChaoNode {
        int s;
        int e;
        int m;
        LiChaoNode.Line cur;
        LiChaoNode lt;
        LiChaoNode rt;

        public LiChaoNode(int ss, int ee, LiChaoNode.Line l) {
            s = ss;
            e = ee;
            m = (s + e) >> 1;
            cur = l;
        }

        public void insert(LiChaoNode.Line l) {
            if (cur == null) {
                cur = l;
                return;
            }
            boolean b1 = l.eval(s) < cur.eval(s);
            boolean b2 = l.eval(m) < cur.eval(m);
            if (b2) {
                LiChaoNode.Line t = l;
                l = cur;
                cur = t;
            }
            if (s == e) return;
            if (b1 != b2) {
                if (lt == null) lt = new LiChaoNode(s, m, l);
                else lt.insert(l);
            } else {
                if (rt == null) rt = new LiChaoNode(m + 1, e, l);
                else rt.insert(l);
            }
        }

        public long query(int x) {
            long y = cur.eval(x);
            if (x < m && lt != null) y = Math.min(y, lt.query(x));
            if (x > m && rt != null) y = Math.min(y, rt.query(x));
            return y;
        }

        public static class Line {
            long m;
            long c;

            public Line(long mm, long cc) {
                m = mm;
                c = cc;
            }

            long eval(long x) {
                return m * x + c;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 20];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}

