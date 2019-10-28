#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
using namespace std;
const int N = 4e6+10;
vector<int>adj[N];
vector<int>color(N, -1);
bool check=true;
void dfs(ll x, int a){
    if(!check){return;}
    if(color[x] != -1){
        if((a^color[x]) == 0){return ;}
        else
        {
            check=false;
            return;
        }
    }
    color[x] = a;
    for(auto i:adj[x]){
        dfs(i, (a^1));
    }
}
int main(){
    ll n, m;
    cin>>n>>m;
    ll k = n+1;
    for(ll i=0; i<m; i++){
        ll x, y, z;
        cin>>x>>y>>z;
        if(z%2 == 1){
        adj[x].pb(y);
        adj[y].pb(x);}
        else{
            adj[x].pb(k);
            adj[y].pb(k);
            adj[k].pb(x);
            adj[k].pb(y);
            k++;
        }
    }

    for(ll i=1; i<=k-1; i++){
        if(!check)
        {
            break;
        }
        if(color[i] != -1){continue;}
        dfs(i, 1);
    }
    if(check){cout<<"YES";}
    else{
        cout<<"NO";
    }
}