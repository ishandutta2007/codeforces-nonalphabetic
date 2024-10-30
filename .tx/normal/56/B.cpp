#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int a[1111];

int main() {
    scid(n);
    rea(a, n);
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 != i) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        cout << "0 0";
        return 0;
    }
    r = n - 1;
    for (int i = l + 1; i < n; i++) {
        if (a[i] + 1 != a[i - 1]) {
            r = i - 1;
            break;
        }
    }
    reverse(a + l, a + r + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 != i) {
            cout << "0 0";
            return 0;
        }
    }
    cout << l + 1 << " " << r + 1;

    return 0;
}