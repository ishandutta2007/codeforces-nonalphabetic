#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	rep(_,0,n){
		int n;
		cin >> n;

		ll sm = 0, xr = 0;
		rep(_,0,n){
			int x;
			cin >> x;
			sm += x;
			xr ^= x;
		}

		cout << 3 << endl;

		ll x = (1LL<<55) + sm%2;
		cout << x;
		sm += x;
		xr ^= x;

		ll y = (2*xr - sm) / 2;
		rep(_,0,2) cout << " " << y;
		cout << endl;
	}
}