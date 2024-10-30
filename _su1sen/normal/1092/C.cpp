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
void chmin(T &x, T &y) { if (y < x) x = y; }
template <typename T>
void chmax(T &x, T &y) { if (y > x) x = y; }

#pragma endregion

// ! code from here

int main() {
    int n;
    read(n);
    vec<string> strs(2 * n - 2);
    read(strs);
    vec<int> p(2 * n - 2);
    iota(all(p), 0);
    sort(all(p), [&strs](int i, int j) { return strs[i].size() < strs[j].size(); });
    string x = strs[p[2 * n - 4]], y = strs[p[2 * n - 3]];
    vec<char> ans(2 * n - 2);
    if (x[0] + y == x + y[n - 2]) {
        string t = x + y[n - 2];
        bool ok = true;
        rep(i, n - 1) {
            if (strs[p[2 * i]] == t.substr(0, i + 1) and strs[p[2 * i + 1]] == t.substr(n - i - 1, i + 1)) {
                ans[p[2 * i]] = 'P';
                ans[p[2 * i + 1]] = 'S';
            } else if (strs[p[2 * i + 1]] == t.substr(0, i + 1) and strs[p[2 * i]] == t.substr(n - i - 1, i + 1)) {
                ans[p[2 * i]] = 'S';
                ans[p[2 * i + 1]] = 'P';
            } else {
                ok = false;
            }
        }
        if (ok) {
            for (char c : ans) cout << c;
            cout << '\n';
            return 0;
        }
    }
    string t = y + x[n - 2];
    bool ok = true;
    rep(i, n - 1) {
        if (strs[p[2 * i]] == t.substr(0, i + 1) and strs[p[2 * i + 1]] == t.substr(n - i - 1, i + 1)) {
            ans[p[2 * i]] = 'P';
            ans[p[2 * i + 1]] = 'S';
        } else if (strs[p[2 * i + 1]] == t.substr(0, i + 1) and strs[p[2 * i]] == t.substr(n - i - 1, i + 1)) {
            ans[p[2 * i]] = 'S';
            ans[p[2 * i + 1]] = 'P';
        } else {
            ok = false;
        }
    }
    assert(ok);
    for (char c : ans) cout << c;
    cout << '\n';
    return 0;
}