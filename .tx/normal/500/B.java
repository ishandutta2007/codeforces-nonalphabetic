import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    int n;
    char[][] b;
    boolean[] used;

    void dfs(int v, List<Integer> comp) {
        used[v] = true;
        comp.add(v);
        for (int i = 0; i < n; i++) {
            if (!used[i] && b[v][i] == '1') {
                dfs(i, comp);
            }
        }
    }

    void solve() throws IOException {
        n = nextInt();
        int[] a = nextIntArray(n);
        b = new char[n][];
        for (int i = 0; i < n; i++) {
            b[i] = next().toCharArray();
        }
        used = new boolean[n];
        List<List<Integer>> comps = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                List<Integer> comp = new ArrayList<>();
                dfs(i, comp);
                Collections.sort(comp);
                comps.add(comp);
            }
        }
        for (List<Integer> comp : comps) {
            int len = comp.size();
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    int x = comp.get(i);
                    int y = comp.get(j);
                    if (a[x] > a[y]) {
                        int _ = a[x];
                        a[x] = a[y];
                        a[y] = _;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            print(a[i]);
            print(" ");
        }
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
}