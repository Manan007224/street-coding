import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Mobilization_lewin {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Mobilization solver = new Mobilization();
        solver.solve(1, in, out);
        out.close();
    }

    static class Mobilization {
        int n;
        int budget;
        double[] x;
        double[] y;

        public boolean ccw(int i, int j, int k) {
            return (y[k] - y[i]) * (x[j] - x[i]) > (y[j] - y[i]) * (x[k] - x[i]);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            budget = in.nextInt();
            x = new double[n];
            y = new double[n];
            for (int i = 0; i < n; i++) {
                double cost = in.nextInt();
                x[i] = in.nextDouble() / cost;
                y[i] = in.nextDouble() / cost;
            }
            int[] order = AUtils.getIndex(n, Comparator.comparingDouble(g -> x[g] * 10000 + y[g]));
            int[] stack = new int[n];
            int sidx = 0;
            for (int _i = 0; _i < n; _i++) {
                int i = order[_i];
                while (sidx > 1 && ccw(stack[sidx - 2], stack[sidx - 1], i)) sidx--;
                stack[sidx++] = i;
            }
            double ans = 0;
            for (int i = 0; i < sidx; i++) {
                double cx = x[stack[i]], cy = y[stack[i]];
                ans = Math.max(ans, cx * cy);
                if (i > 0) {
                    double px = x[stack[i - 1]], py = y[stack[i - 1]];
                    double c = px * py;
                    double b = (cx - px) * py + (cy - py) * px;
                    double a = (cx - px) * (cy - py);
                    double g = Math.max(0, Math.min(1, -b / 2.0 / a));
                    if (Math.abs(a) < 1e-9)
                       g = 0;
                    ans = Math.max(ans, g * g * a + g * b + c);
                }
            }
            out.printf("%.2f\n", ans * budget * budget);
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

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
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

        public double nextDouble() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            double res = 0.0D;

            while (true) {
                if (!isSpaceChar(c) && c != 46) {
                    if (c != 101 && c != 69) {
                        if (c >= 48 && c <= 57) {
                            res *= 10.0D;
                            res += (double) (c - 48);
                            c = this.read();
                            continue;
                        }

                        throw new InputMismatchException();
                    }

                    return res * Math.pow(10.0D, (double) this.nextInt());
                }

                if (c == 46) {
                    c = this.read();

                    for (double m = 1.0D; !isSpaceChar(c); c = this.read()) {
                        if (c == 101 || c == 69) {
                            return res * Math.pow(10.0D, (double) this.nextInt());
                        }

                        if (c < 48 || c > 57) {
                            throw new InputMismatchException();
                        }

                        m /= 10.0D;
                        res += (double) (c - 48) * m;
                    }
                }

                return res * (double) sgn;
            }
        }

    }

    static class AUtils {
        public static int[] getIndex(int n, Comparator<Integer> comp) {
            Integer[] index = new Integer[n];
            for (int i = 0; i < n; i++) index[i] = i;
            Arrays.sort(index, comp);
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) ret[i] = index[i];
            return ret;
        }

    }
}

