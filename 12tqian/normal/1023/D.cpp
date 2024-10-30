#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

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
vi a;
const int MAX = 2e5 + 5;
int b [MAX];
int ending [MAX];
int beginning[MAX];
int mn[MAX];
vi open;
int main(){
    fast_io();
    int n, q;
    cin >> n >> q;
    bool isTrue = false;
    bool isZero = false;
    f0r(i, n){
        int d;
        cin >> d;
        a.eb(d);
        if(d == q){
            isTrue = true;
        }
        if(d == 0){
            isZero = true;
        }
    }

    int color = -1;
    f0r(i, n){
        if(a[i] != 0){
            color = a[i];
            break;
        }
    }
    if(isTrue == false&& isZero){
        f0r(i, n){
            if(a[i] == 0){
                a[i] = q;
                break;
            }
        }
        isTrue =true;
    }

    if(isTrue == false && color != -1){
        cout << "NO";
        return 0;
    }
    if(color == -1){
        cout << "YES" << endl;
        f0r(i, n){
            cout << q << " ";

        }
    return 0;
    }
    int prev = color;
    f0r(i, n){
        if(a[i] == 0){
            a[i] = prev;
        }
        else{
            prev = a[i];
        }
    }

    f0r(i, MAX){
        beginning[i] = -1;
        ending[i] = -1;
    }
    for(int i = n-1; i>= 0; i--){
        if(ending[a[i]] == -1){
            ending[a[i]] = i;
        }
    }
    f0r(i, n){
        if(beginning[a[i]] == -1){
            beginning[a[i]] = i;
        }
    }
    f0r(i, MAX){
        mn[i] = 2e5+10;
    }
    int idx = 0;
    f0r(i, n){
        int cur = a[i];
        if(b[cur] == 0){
            if(open.size() == 1){
                if(open[0]>cur){
                    cout << "NO";
                    return 0;
                }
            }
            if(open.size() != 1 && cur < mn[idx -1]){
                cout << "NO";
                return 0;
            }
        }
        if(b[cur] == 0 && i == beginning[cur] && i != ending[cur]){
            b[cur] = 1;
            open.eb(cur);
            if(idx == 0){
                mn[idx] = min(mn[idx], cur);
            }
            else{
                mn[idx] = min(mn[idx-1], cur);
            }
            idx += 1;
        }
        if(b[cur] == 1){
            if(open[open.size() - 1] != cur){
                cout << "NO";
            //    cout << i << " " << cur << " " << open[sz(open) - 1] << endl;
                return 0;
            }
            if(i == ending[cur]){
                b[cur] = 0;
                open.pop_back();
                mn[idx] = 2e5 + 10;
                idx--;
            }
        }
    }
    cout << "YES" << endl;
    for(int i : a){
        cout << i << " ";
    }
    return 0;
}