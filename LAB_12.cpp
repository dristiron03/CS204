#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
const int N=1e6+5;
long long int mod = (ll)1e9+7;
ll parent[N],size[N];
void make(ll v)
{
    parent[v] = v;
    size[v] = 1;
}

ll find(ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void merge(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
struct edge
{
    ll u, v, weight;
    bool operator<(edge const &other)
    {
        return weight > other.weight;
    }
};
int main()
{
    ll n,m,u,v,w;
    cin>>n>>m;
    for(int i=1;i<=n;i++)make(i);
    vector<edge> edges,vk;
    for(int i=0;i< m; i++)
    {
        cin>>u>>v>>w;
        edges.pb({u,v,w});
    }
    ll cost = 1;
    sort(edges.begin(), edges.end());
    for (edge e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            cost =(cost*(e.weight%mod))%mod;
            vk.pb(e);
            merge(e.u, e.v);
        }
    }
    cout<<cost;
    return 0;
}