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

int b[222222];
int c[222222];

int main() {
    scid(n);
    map<int, int> ca;
    for (int i = 0; i < n; i++) {
        scid(x);
        ca[x]++;
    }
    scid(m);
    rea(b, m);
    rea(c, m);
    int ai = -1;
    pair<int, int> ma(-1, -1);
    for (int i = 0; i < m; i++) {
        pair<int, int> cur(ca[b[i]], ca[c[i]]);
        if (cur > ma) {
            ma = cur;
            ai = i;
        }
    }

    cout << ai + 1;

    return 0;
}