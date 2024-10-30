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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    read(t);
    while (t --> 0) {
        int n, k;
        read(n, k);
        vec<vec<int>> g(n);
        rep(i, n - 1) {
            int u, v;
            read(u, v);
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vec<char> is_leaf(n, false);
        vec<int> leaves(n, 0);
        rep(i, n) {
            if (g[i].size() == 1) {
                is_leaf[i] = true;
                ++leaves[g[i][0]];
            }
        }
        auto cmp = [&leaves](int i, int j) {
            return leaves[i] == leaves[j] ? i < j : leaves[i] > leaves[j];
        };
        set<int, decltype(cmp)> st(cmp);
        rep(i, n) st.insert(i);
        int ans = 0;
        while (st.size()) {
            int u = *st.begin();
            if (leaves[u] < k) break;
            int rem = k * (leaves[u] / k), cnt = 0;
            int sz = g[u].size();
            rep(i, sz) {
                while (i < sz and cnt < rem and is_leaf[g[u][i]]) {
                    is_leaf[g[u][i]] = false;
                    st.erase(g[u][i]);
                    swap(g[u][i], g[u][--sz]);
                    g[u].pop_back();
                    ++cnt;
                }
            }
            st.erase(u);
            leaves[u] -= rem;
            st.insert(u);
            ans += rem / k;
            if (g[u].size() == 1) {
                is_leaf[u] = true;
                int p = g[u][0];
                st.erase(p);
                ++leaves[p];
                st.insert(p);
            }
        }
        print(ans);
    }
    return 0;
}