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
	
	int n, k;
	cin >> n >> k;
	vi as(k, (n-1)/k);
	rep(i,0,(n-1)%k) ++as[i];
	cout << as[0]+as[1] << endl;
	int ix = 2;
	trav(x, as){
		int pr = 1;
		rep(_,0,x){
			cout << pr << ' ' << ix << endl;
			pr = ix++;
		}
	}
}