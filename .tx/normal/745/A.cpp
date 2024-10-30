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

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scids(s);
    set<string> a;
    for (int i = 0; i < 50; i++) {
        a.insert(s);
//        cerr << s << endl;
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    cout << a.size();
    
    return 0;
}