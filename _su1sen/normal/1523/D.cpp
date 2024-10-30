#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
using ll = long long;
using uint = unsigned int;
using ull  = unsigned long long;

template <typename T> using vec  = std::vector<T>;
template <typename T> using vec2 = vec<vec<T>>;
template <typename T> using vec3 = vec<vec2<T>>;
template <typename T> using vec4 = vec<vec3<T>>;

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
#define size_as_int(iterable) int((iterable).size())
#define input(type, ...) type __VA_ARGS__; read(__VA_ARGS__)

// ! constants
constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

constexpr int IINF = (1 << 30) - 1;
constexpr ll LINF = (1LL << 62) - 1; 

// ! I/O utilities
template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> &a) {
    int n = a.size();
    rep(i, n) {
        out << a[i];
        if (i < n - 1) out << ' ';
    }
    return out;
}
template <typename T>
void print(const vec<T>& v, const string sep = " ", const string end = "\n") {
    int n = v.size();
    rep(i, n) {
        cout << v[i];
        if (i < n - 1) cout << sep;
    }
    cout << end;
}
template <typename T>
void print(const vec<T>& v, const size_t begin_index, const size_t length, const string sep = " ", const string end = "\n") {
    int n = begin_index + length;
    replr(i, begin_index, n) {
        cout << v[i];
        if (i < n - 1) cout << sep;
    }
    cout << end;
}
inline void print() { cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail&... tails) {
    cout << head;
    if (sizeof...(tails)) cout << ' ';
    print(tails...);
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T> &a) {
    for (T& v : a) in >> v;
    return in;
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
constexpr void read() {}
template <typename Head, typename... Tail>
inline void read(Head& head, Tail& ...tails) {
    cin >> head;
    read(tails...);
}

// ! utility functions
template <typename T>
bool chmin(T &x, const T &y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmin(T &x, const T &&y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, const T &&y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

// ! operator overload (pair)
template <typename T, typename U>
std::pair<T, U>& operator+=(std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    p1.first += p2.first, p1.second += p2.second;
    return p1;
}
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}
template <typename T, typename U>
std::pair<T, U>& operator-=(std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    p1.first -= p2.first, p1.second -= p2.second;
    return p1;
}
template <typename T, typename U>
std::pair<T, U> operator-(const std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
template <typename T, typename U, typename V>
std::pair<T, U>& operator*=(std::pair<T, U> &p, const V m) {
    p.first *= m, p.second *= m;
    return p;
}
template <typename T, typename U, typename V>
std::pair<T, U> operator*(std::pair<T, U> &p, const V m) {
    return {p.first * m, p.second * m};
}
// ! operator overload (vector)
template <typename T>
std::vector<T>& operator+=(std::vector<T> &a, const std::vector<T> &b) {
    int n = a.size();
    a.resize(n + b.size());
    std::copy(b.begin(), b.end(), a.begin() + n);
    return a;
}
template <typename T>
std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> c = a; return c += b;
}
template <typename T>
std::vector<T>& operator+=(std::vector<T> &a, const T &b) {
    a.push_back(b); return a;
}
template <typename T>
std::vector<T> operator+(const std::vector<T> &a, const T &b) {
    std::vector<T> c = a; return c += b;
}
template <typename T>
std::vector<T>& operator+=(std::vector<T> &a, const T &&b) {
    a.push_back(b); return a;
}
template <typename T>
std::vector<T> operator+(const std::vector<T> &a, const T &&b) {
    std::vector<T> c = a; return c += b;
}
template <typename T>
std::vector<T>& operator*=(std::vector<T> &a, const int repeat) {
    int n = a.size();
    a.resize(n * repeat);
    for (int i = 1; i < repeat; ++i) std::copy(a.begin(), a.end(), a.begin() + i * n);
    return a;
}
template <typename T>
std::vector<T> operator*(std::vector<T> &a, const int repeat) {
    std::vector<T> c = a; return c *= repeat;
}
// ! operator overload (priority_queue)
template <typename _Tp, typename _Sequence, typename _Compare>
std::priority_queue<_Tp, _Sequence, _Compare>& operator+=(std::priority_queue<_Tp, _Sequence, _Compare> &a, const _Tp &b) {
    a.push(b); return a;
}
template <typename _Tp, typename _Sequence, typename _Compare>
std::priority_queue<_Tp, _Sequence, _Compare>& operator+=(std::priority_queue<_Tp, _Sequence, _Compare> &a, const _Tp &&b) {
    a.push(b); return a;
}
// ! operator overload (set)
template <typename _Key, typename _Compare, typename _Alloc>
std::set<_Key, _Compare, _Alloc>& operator+=(std::set<_Key, _Compare, _Alloc> &a, const _Key &b) {
    a.insert(b); return a;
}
template <typename _Key, typename _Compare, typename _Alloc>
std::set<_Key, _Compare, _Alloc>& operator+=(std::set<_Key, _Compare, _Alloc> &a, const _Key &&b) {
    a.insert(b); return a;
}
template <typename _Key, typename _Compare, typename _Alloc>
std::set<_Key, _Compare, _Alloc>& operator-=(std::set<_Key, _Compare, _Alloc> &a, const _Key &b) {
    a.erase(b); return a;
}
template <typename _Key, typename _Compare, typename _Alloc>
std::set<_Key, _Compare, _Alloc>& operator-=(std::set<_Key, _Compare, _Alloc> &a, const _Key &&b) {
    a.erase(b); return a;
}
// ! extension methods

#pragma endregion

// ! code from here

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input(int, n, m, p);
    vec<int> c(m);
    vec<ll> ss(n);
    rep(i, n) {
        ll st = 0;
        input(string, s);
        rep(j, m) {
            st <<= 1;
            st |= s[j] - '0';
        }
        ss[i] = st;
        rep(j, m) {
            c[j] += (st >> j) & 1;
        }
    }
    map<ll, int> cs;
    int need = (n + 1) / 2;
    rep(j, m) {
        if (c[j] < need) {
            rep(i, n) {
                ss[i] &= -1LL ^ (1LL << j);
            }
        }
    }
    rep(i, n) ++cs[ss[i]];
    map<ll, int> cnt;
    for (auto [st, c] : cs) {
        for (ll t = st; t > 0; t = (t - 1) & st) {
            cnt[t] += c;
        }
        cnt[0] += c;
    }
    
    int mx = 0;
    ll arg = 0;
    for (auto [s, c] : cnt) {
        if (c >= need and chmax(mx, __builtin_popcountll(s))) {
            arg = s;
        }
    }
    vec<char> ans;
    while (arg) {
        ans.push_back('0' + (arg & 1));
        arg >>= 1;
    }
    int sz = ans.size();
    rep(i, m - sz) {
        ans.push_back('0');
    }
    reverse(all(ans));
    rep(i, m) {
        cout << ans[i];
        if (i == m - 1) cout << '\n';
    }
    return 0;
}