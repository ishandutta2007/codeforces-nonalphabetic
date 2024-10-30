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

int main() {
    lint n, a, b, c;
    cin >> n >> a >> b >> c;
    if (b > n || b - c >= a) {
        cout << n / a;
        return 0;
    }
    lint x = (n - b) / (b - c);
    n = n - x * (b - c);
    while (n >= b) {
        n -= b - c;
        x++;
    }
    lint y = n / min(a, b);
    cout << x + y;

    return 0;
}