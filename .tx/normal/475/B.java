import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;
    int mod = inf + 7;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[][] d = new int[n * m][n * m];
        for (int[] i : d) {
            Arrays.fill(i, inf);
        }
//        for (int i = 0; i < n - 1; i++) {
//            for (int j = 0; j < m; j++) {
//                d[i * m + j][(i + 1) * m + j] = d[(i + 1) * m + j][i * m + j] = 1;
//            }
//        }
        char[] s = next().toCharArray();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '<') {
                for (int j = m - 1; j > 0; j--) {
                    d[i * m + j][i * m + j - 1] = 1;
                }
            } else {
                for (int j = 0; j < m - 1; j++) {
                    d[i * m + j][i * m + j + 1] = 1;
                }
            }
        }
        s = next().toCharArray();
        for (int j = 0; j < m; j++) {
            char c = s[j];
            if (c == 'v') {
                for (int i = 0; i < n - 1; i++) {
                    d[i * m + j][(i + 1) * m + j] = 1;
                }
            } else {
                for (int i = n - 1; i > 0; i--) {
                    d[i * m + j][(i - 1) * m + j] = 1;
                }
            }
        }
        for (int k = 0; k < n * m; k++) {
            for (int i = 0; i < n * m; i++) {
                for (int j = 0; j < n * m; j++) {
                    if (d[i][k] != inf && d[k][j] != inf) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
        for (int i = 0; i < n * m; i++) {
            for (int j = 0; j < n * m; j++) {
                if (i != j && d[i][j] == inf) {
                    println("NO");
                    return;
                }
            }
        }
        println("YES");
    }

    void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        } finally {
            close();
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String filename) throws IOException {
        super("".equals(filename) ? "output.txt" : filename + ".out");
        in = new BufferedReader(new FileReader("".equals(filename) ? "input.txt" : filename + ".in"));
    }

    public static void main(String[] args) throws IOException {
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

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
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

    class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
        A a;
        B b;

        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Pair<A, B> o) {
            int aa = a.compareTo(o.a);
            return aa == 0 ? b.compareTo(o.b) : aa;
        }
    }
}