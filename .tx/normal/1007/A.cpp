#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> q(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.top() <= a[i]) {
            q.pop();
        }
        if (!q.empty()) {
            ans++;
            q.pop();
        }
    }

    cout << ans;

    return 0;
}