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
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp = std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    if (n <= 2) {
        cout << "1\n";
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
        return 0;
    }
    cout << "2\n";
    for (int i = 2; i <= n + 1; i++) {
        bool pr = true;
        for (int j = 2; 1LL * j * j <= i; j++) {
            if (i % j == 0) {
                pr = false;
                break;
            }
        }
        if (pr) {
            cout << "1 ";
        } else {
            cout << "2 ";
        }
    }

    return 0;
}