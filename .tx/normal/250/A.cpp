#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    scid(n);
    vector<int> ans;
    int k = 0;
    int kn = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        k++;
        if (x < 0) {
            kn++;
        }
        if (kn == 3) {
            ans.push_back(k - 1);
            k = 1;
            kn = 1;
        }
    }
    ans.push_back(k);
    printf("%d\n", ans.size());
    for (int i : ans) {
        printf("%d ", i);
    }
    return 0;
}