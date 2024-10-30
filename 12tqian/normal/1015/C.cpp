#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const int MAX = 1e5 + 5;
static ll prefix[MAX];
vector<pair<ll, ll>> a;
int main(){
    fast_io();
    ll n, m;
    cin >> n >> m;
    f0r(i, n){
        ll x, y;
        cin >> x >> y;
        a.eb(mp(x-y, x));
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    prefix[n-1] = a[n-1].s;
    for(int i = n-2; i>=0; i--){
        prefix[i] = prefix[i+1] + a[i].s;
    }
    ll sum = 0;
    for(int i = 0; i<n;i++){
        if(prefix[0] <= m){
            cout << 0 << endl;
            return 0;
        }
        if(sum + prefix[i]<=m){
            cout << i;
            return 0;
        }
        sum += (a[i].s - a[i].f);
    }
    if(sum <= m){
        cout << n;
        return 0;
    }
    cout << -1;
    return 0;
}