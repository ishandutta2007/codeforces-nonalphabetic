#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const double PI = atan(1) * 4;

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        double n;
        cin >> n;
        n *= 2;
        double ang = 360 / n;
        ang /= 2;
        double len = 0.5 / tan(ang / 180 * PI);
        printf("%.10f\n", len * 2);
    }


    return 0;
}