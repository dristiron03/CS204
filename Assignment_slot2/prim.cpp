//Question Link-> https://www.hackerrank.com/challenges/primsmstsub/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
const int N = 2e5+5;
bool vis[N];
vector<pair<ll, ll> >adj[N];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >pq;
ll ans=0;
int main(){
    ll n, m;
    cin>>n>>m;
    while(m--){
        ll x, y, z;
        cin>>x>>y>>z;
        adj[x].pb({y, z});
        adj[y].pb({x, z});
    }
    ll a;
    cin>>a;
    pq.push({0, a});
    while(!pq.empty()){
        ll x = pq.top().ss;
        ll y= pq.top().ff;
        pq.pop();
        if(vis[x]){continue;}
        vis[x] = true;
        ans+=y;
        for(auto i:adj[x]){
            if(vis[i.ff]){continue;}
            pq.push({i.ss, i.ff});
        }
    }
    cout<<ans;
}