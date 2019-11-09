//Question Link-> https://www.hackerrank.com/challenges/kruskalmstrsub/copy-from/125863890
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
 
int modInverse(int a, int m);
int power(int x, unsigned int y, unsigned int m);
int logint(int x,int y); 
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {// q is quotient
        int q = a / m;
        int t = m;
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
void pairsort(int a[],int b[], int n)
{   pair<int, int> pairt[n];
    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {   pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
    // Sorting the pair array.
    sort(pairt, pairt + n);
    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {   a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}
int logint(int x,int y)
{   int ans=0;
    int a=1;
    for(int i=0;i<x;i++)
    {   if(x<=a)
        {    return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}
vector<tuple<ll, ll, ll> > edge;
vector<ll>parent(3001), rr(3001);
void make_set(ll i){
    parent[i] = i;
    rr[i] = 0;
}
ll find(ll v){
    if(v == parent[v]){return v;}
    return find(parent[v]);
}
void uni(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(rr[a] < rr[b]){
            swap(a, b);}
        parent[b] = a;
        if(rr[a] == rr[b]){
            rr[a]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, m;
    cin>>n>>m;
    REP(i, 0, m){
        ll x, y, z;
        cin>>x>>y>>z;
        edge.pb({z, x, y});
    }
    ll cost=0;
    REP(i, 0, n+1){
        make_set(i);
    }
    sort(edge.begin(), edge.end());
    for(auto x:edge){
        if(find(get<1>(x)) != find(get<2>(x))){
            cost += get<0>(x);
            uni(get<1>(x), get<2>(x));
        }
    }
    cout<<cost;
}
