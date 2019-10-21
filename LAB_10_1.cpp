#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define M2 998244353
#define ll long long
#define pll pair<long,long>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define ff first
#define ss second
#define pb push_back
#define db pop_back
#define mp make_pair
#define mt make_tuple
#define g(a,b) get<a>(b)
#define INF 1e18
 
#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
 
ll modI(ll a, ll m);
ll gcd(ll a, ll b);
ll powM(ll x, unsigned ll y, unsigned ll m);
void pairsort(int a[], int b[], int n);
void pairsortll(ll a[],ll b[],ll n);
ll logint(ll x,ll y);
 
 
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
 
ll powM(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=powM(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
 
ll modI(ll a, ll m)
{
   return powM(a, m-2, m);
}
 
void pairsort(int a[],int b[],int n)
{
    pair<int,int> v[n];
    REP(i,0,n)
    {
        v[i].ff=a[i];
        v[i].ss=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].ff;
        b[i]=v[i].ss;
    }
}
 
void pairsortll(ll a[],ll b[],ll n)
{
    pair<ll,ll> v[n];
    REP(i,0,n)
    {
        v[i].ff=a[i];
        v[i].ss=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].ff;
        b[i]=v[i].ss;
    }
}
 
ll logint(ll x,ll y)
{
    ll ans=0;
    ll a=1;
    for(ll i=0;i<=x;i++)
    {
        if(x<a)
        {
            return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}
const int N = (int)1e6+5;
ll parent[N];
ll siz[N];
ll m, n;
vector<pair<ll, ll> >ad[2];
void make(ll i){
        parent[i]=i;
        siz[i] = 1;
}
ll find(ll v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find(parent[v]);
}
void unite(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(siz[a] < siz[b]){
            swap(a, b);}
        parent[b] = a;
        siz[a] += siz[b];
    }
}
ll index(ll i, ll j){
    return i*m+j;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>m>>n;
    ll k;
    cin>>k;
    REP(i, 0, k){
        ll x, y;
        cin>>x>>y;
        ad[0].pb({x,y});
        ad[1].pb({y, x});
        make(index(x, y));
    }
    sort(ad[0].begin(), ad[0].end());
    sort(ad[1].begin(), ad[1].end());
    REP(i, 0, k-1){
        if(ad[0][i].ff == ad[0][i+1].ff && ad[0][i+1].ss == ad[0][i].ss+1 || ad[0][i].ff+1 == ad[0][i+1].ff && ad[0][i].ss == ad[0][i+1].ss){
            unite(index(ad[0][i].ff, ad[0][i].ss), index(ad[0][i+1].ff, ad[0][i+1].ss));
        }
    }
    REP(i, 0, k-1){
        if(ad[1][i].ff == ad[1][i+1].ff && ad[1][i+1].ss == ad[1][i].ss+1 || ad[1][i].ff+1 == ad[1][i+1].ff && ad[1][i].ss == ad[1][i+1].ss){
            unite(index(ad[1][i].ss, ad[1][i].ff), index(ad[1][i+1].ss, ad[1][i+1].ff));
        }
    }

    ll maxi = -1;
    REP(i, 0, k){
        ll j = find(index(ad[0][i].ff, ad[0][i].ss));
        if(siz[j] > maxi){
            maxi = siz[j];
        }
    }
    cout<<maxi; 
}