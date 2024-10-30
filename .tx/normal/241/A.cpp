#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int s[1111];
int d[1111];

int main() {
    sciid(m, k);
    for (int i = 0; i < m; i++) {
        sci(d[i]);
    }
    for (int i = 0; i < m; i++) {
        sci(s[i]);
    }
    int ans = 0;
    int cc = 0;
    int mx = 0;
    for (int i = 0; i < m; i++) {
        cc += s[i];
        mx = max(mx, s[i]);
        if (cc < d[i]) {
            int t = (d[i] - cc + mx - 1) / mx;
            ans += t * k;
            cc += mx * t;
        }
        cc -= d[i];
        ans += d[i];
    }

    cout << ans;
    return 0;
}