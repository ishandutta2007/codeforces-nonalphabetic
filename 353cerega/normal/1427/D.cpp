#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define X first
#define Y second

ll mod = 998244353;

ll gcd(ll a, ll b)
{
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}

ll sum(ll a, ll b)
{
    a += b;
    a %= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a += mod-b;
    a %= mod;
    return a;
}

ll mul(ll a, ll b)
{
    return a*b%mod;
}

ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = mul(res,a);
        a = mul(a,a);
        b /= 2;
    }
    return res;
}

/*
typedef complex<double> base;
long double PI = acos(-1);
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    if (n == 1)  return;

    vector<base> a0 (n/2),  a1 (n/2);
    for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);

    double ang = 2*PI/n * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i+n/2] /= 2;
        w *= wn;
    }
}
*/
int parent[100001];
int rnk[100001];

void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}

/*
ll t[2000001];

void build()
{
    for (int i=0;i<2000000;i++)
    {
        t[i] = 0;
    }
}

void update (int v, int tl, int tr, int pos, ll add) {
    t[v] += add;
    if (tl==tr) return;
    int tm = (tl + tr) / 2;
    if (tm>=pos)
    {
        update(v * 2, tl, tm, pos, add);
    } else
    {
        update (v*2+1, tm+1, tr, pos, add);
    }
}

ll get (int v, int tl, int tr, int l, int r) {
    if (tl == l and tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}


ll base = 1000000000;

vector<ll> mul(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<a.size();i++)
    {
        for (int j=0;j<b.size();j++)
        {
            res[i+j] += a[i]*b[j];
        }
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sum(vector<ll> a, vector<ll> b)
{
    if (a.size()<b.size())
    {
        swap(a,b);
    }
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]+b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sub(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]-b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]<0)
        {
            res[i+1]--;
            res[i] += base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}
*/



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> ans;
    while (true)
    {
        int flag = 0;
        for (int i=1;i<n;i++)
        {
            if (a[i]<a[i-1]) flag = 1;
        }
        if (flag==0) break;
        vector<int> pos(n+1);
        for (int i=0;i<n;i++)
        {
            pos[a[i]] = i;
        }
        for (int j=1;j<n;j++)
        {
            if (pos[j]>pos[j+1])
            {
                int sz = 1;
                while (j-sz>0 and pos[j-sz]==pos[j]-sz)
                {
                    sz++;
                }
                vector<int> tmp;
                if (pos[j+1]>0)
                {
                    tmp.push_back(pos[j+1]);
                }
                tmp.push_back(pos[j]-pos[j+1]-sz+1);
                tmp.push_back(sz);
                if (pos[j]!=n-1)
                {
                    tmp.push_back(n-1-pos[j]);
                }
                vector<int> b;
                for (int l=pos[j]+1;l<n;l++)
                {
                    b.push_back(a[l]);
                }
                for (int l=pos[j]-sz+1;l<=pos[j];l++)
                {
                    b.push_back(a[l]);
                }
                for (int l=pos[j+1];l<=pos[j]-sz;l++)
                {
                    b.push_back(a[l]);
                }
                for (int l=0;l<pos[j+1];l++)
                {
                    b.push_back(a[l]);
                }
                a = b;
                ans.push_back(tmp);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++)
    {
        cout << ans[i].size();
        for (int j=0;j<ans[i].size();j++)
        {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
}