#include <bits/stdc++.h>

#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

template <typename T>
using vec = std::vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
template <typename T>
using vec3 = vec<vec2<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = unordered_map<T, U>;

// ! macros
#define rep(i, n)           for (int i = 0; i < n; ++i)
#define reps(i, n, s)       for (int i = 0; i < n; i += s)
#define replr(i, l, r)      for (int i = l; i < r; ++i)
#define replrs(i, l, r, s)  for (int i = l; i < r; i += s)
#define rrep(i, n)          for (int i = (n) - 1; i >= 0; --i)
#define rreps(i, n, s)      for (int i = (n) - 1; i >= 0; i -= s)
#define rreplr(i, l, r)     for (int i = (r) - 1; i >= l; --i)
#define rreplrs(i, l, r, s) for (int i = (r) - 1; i >= l; i -= s)

#define all(iterable) (iterable).begin(), (iterable).end()

// ! constants
constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

constexpr int IINF = (1 << 30) - 1;
constexpr ll LINF = (1LL << 62) - 1; 

// ! I/O utilities
inline void print() { cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail&... tails) {
    cout << head;
    if (sizeof...(tails)) cout << ' ';
    print(tails...);
}
template <typename T>
void print(const vec<T>& v, const string sep = " ", const string end = "\n") {
    int n = v.size();
    rep(i, n) cout << v[i] << (i < n - 1 ? sep : end);
}
template <typename T>
void print(const vec<T>& v, const size_t begin_index, const size_t length, const string sep = " ", const string end = "\n") {
    int n = begin_index + length;
    replr(i, begin_index, n) cout << v[i] << (i < n - 1 ? sep : end);
}
constexpr void read() {}
template <typename Head, typename... Tail>
inline void read(Head& head, Tail& ...tails) {
    cin >> head;
    read(tails...);
}
template <typename T>
void read(vec<T>& a, size_t begin_index, size_t length) {
    a.resize(begin_index + length);
    while (length --> 0) cin >> a[begin_index++];
}
template <typename T>
void read(vec<T>& a) {
    read(a, 0, a.size());
}

// ! utility functions
template <typename T>
bool chmin(T &x, T &y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmin(T &x, T &&y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, T &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, T &&y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

#pragma endregion

// ! code from here


class topological_sort {
    public:
        topological_sort(std::vector<std::vector<int>> &g): _n(g.size()) {
            build(g);
        }
        bool is_dag() const { return _ord.size() == _n; }
        const std::vector<int>& sorted() const { return _ord; }
        const int operator[](int i) const { return _ord[i]; }
    private:
        const int _n;
        std::vector<int> _ord;
        void build(std::vector<std::vector<int>> &g) {
            std::vector<int> in(_n);
            for (auto &adj : g) for (int j : adj) ++in[j];
            std::deque<int> dq;
            for (int i = 0; i < _n; ++i) {
                if (in[i] == 0) dq.push_back(i);
            }
            _ord.reserve(_n);
            while (dq.size()) {
                int u = dq.front(); dq.pop_front();
                _ord.push_back(u);
                for (int v : g[u]) {
                    if (--in[v] == 0) dq.push_back(v);
                }
            }
        }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    read(t);
    while (t --> 0) {
        int n, m;
        read(n, m);
        using edge = pair<int, int>;
        vec<edge> ext;
        vec<vec<int>> g(n);
        rep(i, m) {
            int tp, u, v;
            read(tp, u, v);
            --u, --v;
            if (tp == 0) {
                ext.emplace_back(u, v);
            } else {
                g[u].push_back(v);
            }
        }
        topological_sort ts(g);
        if (ts.is_dag()) {
            vec<int> inv(n);
            rep(i, n) inv[ts[i]] = i;
            print("YES");
            for (auto [u, v] : ext) {
                if (inv[u] > inv[v]) swap(u, v);
                print(u + 1, v + 1);
            }
            rep(i, n) {
                for (int j : g[i]) print(i + 1, j + 1);
            }
        } else {
            print("NO");
        }
    }
    return 0;
}