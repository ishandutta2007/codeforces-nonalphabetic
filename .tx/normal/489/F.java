import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int mod = nextInt();
        long[][] d = new long[n + 1][n + 1];
        long[][] nd = new long[n + 1][n + 1];
        int[] cnt1 = new int[n];
        char[] c = null;
        for (int i = 0; i < m; i++) {
            c = next().toCharArray();
            for (int j = 0; j < n; j++) {
                if (c[j] == '1') {
                    cnt1[j]++;
                }
            }
        }
        int c1 = 0, c0 = 0;
        for (int i = 0; i < n; i++) {
            if (cnt1[i] == 0) {
                c0++;
            } else if (cnt1[i] == 1) {
                c1++;
            }
        }
        d[c0][c1] = 1;
        for (int r = m; r < n; r++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (d[i][j] == 0) {
                        continue;
                    }
                    if (i >= 2) {
                        nd[i - 2][j + 2] += d[i][j] * i * (i - 1) / 2;
                        nd[i - 2][j + 2] %= mod;
                    }
                    if (j >= 2) {
                        nd[i][j - 2] += d[i][j] * j * (j - 1) / 2;
                        nd[i][j - 2] %= mod;
                    }
                    if (i >= 1 && j >= 1) {
                        nd[i - 1][j] += d[i][j] * i * j;
                        nd[i - 1][j] %= mod;
                    }
                }
            }
            for (long[] i : d) {
                Arrays.fill(i, 0);
            }
            long[][] _ = d;
            d = nd;
            nd = _;
        }
        println(d[0][0]);
    }

    public void run() {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws IOException {
        super("".equals(s) ? "output.txt" : (s + ".out"));
        in = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : (s + ".in")));
    }

    public static void main(String[] args) throws IOException {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignored) {
        }
        new Main().run();
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] a = new int[len];
        for (int i = 0; i < len; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[x];
            a[x] = t;
        }
    }

    boolean nextPerm(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1; ; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

    <T> List<T>[] createAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}