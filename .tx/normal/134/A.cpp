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

int a[222222];
int ans[222222];

int main() {
    scid(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        s += a[i];
    }
    int ax = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * (n - 1) == s - a[i]) {
            ans[ax++] = i;
        }
    }
    printf("%d\n", ax);
    for (int i = 0; i < ax; i++) {
        printf("%d ", ans[i] + 1);
    }

    return 0;
}