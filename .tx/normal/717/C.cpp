#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int a[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);

    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    sort(a, a + n);
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + 1LL * a[i] * a[n - 1 - i]) % 10007;
    }
    cout << ans;

    return 0;
}