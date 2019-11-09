//Question_link -> https://www.hackerrank.com/challenges/torque-and-development/problem

#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define N 998244353
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
#define INF 1000000000
 
ll modInverse(ll a, ll m);
ll power(ll x, unsigned ll y, unsigned ll m);
ll logint(ll x,ll y);
ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {// q is quotient
        ll q = a / m;
        ll t = m;
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
        // Update y and x
        y = x - q * y;
        x = t;
    }
    // Make x positive
    if (x < 0)
       x += m0;
    return x;
}
void pairsort(ll a[],ll b[], ll n)
{   pair<ll, ll> pairt[n];
    // Storing the respective array
    // elements in pairs.
    for (ll i = 0; i < n; i++)
    {   pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
    // Sorting the pair array.
    sort(pairt, pairt + n);
    // Modifying original arrays
    for (ll i = 0; i < n; i++)
    {   a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}
ll logint(ll x,ll y)
{   ll ans=0;
    ll a=1;
    for(ll i=0;i<x;i++)
    {   if(x<=a)
        {    return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}
bool vis[100001];
vector<ll>ad[100001];
ll dd=0;
void dfs(ll a){
    dd++;
    vis[a] = true;
    REP(j, 0, ad[a].size()){
        if(!vis[ad[a][j]]){
            dfs(ad[a][j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    ll q;
    cin>>q;
    while(q--){
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        //memset(ar, 0, sizeof(ar));
        memset(vis, false, sizeof(vis));
        REP(i, 0, 100001){
            ad[i].clear();
        }
        REP(i, 0, b){
            ll x, y;
            cin>>x>>y;
            ad[x].pb(y);
            ad[y].pb(x);
        }
        ll ans=0;
        REP(j, 1, a+1){
            if(!vis[j]){
                dd=0;
                dfs(j);
                //cout<<dd<<endl;
                ans += c+(min(c, d)*(dd-1));
            }
        }
        cout<<ans<<endl;
    }
}
