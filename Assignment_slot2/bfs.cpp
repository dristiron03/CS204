//Question link -> https://www.hackerrank.com/challenges/bfsshortreach/copy-from/125834128
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define N 998244353
#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
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
vector<ll>v[1001];
ll ar[1001];
void bfs(ll x){
    queue<ll>q;
    ar[x] = 0;
    q.push(x);
    while(!q.empty()){
        ll t = q.front();
        q.pop();
        for(auto y:v[t]){
            if(ar[y] != -1){continue;}
            ar[y] = ar[t]+1;
            q.push(y);
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
    int q;
    cin>>q;
    while(q--){
        ll n, m;
        cin>>n>>m;
        memset(ar, -1, sizeof(ar));
        REP(i, 1, n+1){
            v[i].clear();
        }
        REP(i, 0, m){
            ll x, y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        ll x;
        cin>>x;
        bfs(x);
        REP(i, 1, n+1){
            if(i==x){continue;}
            if(ar[i] == -1){cout<<ar[i]<<" "; continue;}
            cout<<6*ar[i]<<" ";
        }
        cout<<endl;
        
    }
}

