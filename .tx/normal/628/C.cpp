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

char s[111111];

int main() {
    sciid(n, k);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if ('z' - s[i] > s[i] - 'a') {
            int t = min(k, 'z' - s[i]);
            s[i] += t;
            k -= t;
        } else {
            int t = min(k, s[i] - 'a');
            s[i] -= t;
            k -= t;
        }
    }
    if (k != 0) {
        cout << -1;
    } else {
        puts(s);
    }


    return 0;
}