#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5005;
int parent[N];
int size[N];
int value[N];
int n, m, c;
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
int index(int i, int j)
{
    return i * m + j;
}
int main()
{
    cin >> n >> m >> c;
    int a[n + 2][m + 2];
    memset(a, -1, sizeof(a));
    for(ll i=1; i<= n; i++) for(ll j=1; j<=m; j++)
    {
        cin >> a[i][j];
        make(index(i, j));
    }
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            if (a[i][j] == a[i - 1][j])
                merge(index(i, j), index(i - 1, j));
        }
    }
    for(ll i=1; i<= n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            if (a[i][j - 1] == a[i][j])
                merge(index(i, j - 1), index(i, j));
        }
    }
    ll maxi = -1, color = -1;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            ll x = find(index(i, j));
            if (size[x] > maxi)
            {
                maxi = size[x];
                color = a[i][j];
            }
        }
    }
    cout<<maxi<<" "<<color;
    return 0;
}