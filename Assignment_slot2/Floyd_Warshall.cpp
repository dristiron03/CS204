//Question Link-> https://codeforces.com/problemset/problem/25/C
#include<bits/stdc++.h>
using namespace std;
int adj[301][301];
int main(){
    //memset(adj, 0, adj);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adj[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a, b, c;
        cin>>a>>b>>c;
        long long ans = 0;
        if(adj[a-1][b-1] > c){
            adj[a-1][b-1] = min(c, adj[a-1][b-1]);
            adj[b-1][a-1] = min(c, adj[b-1][a-1]);
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        adj[j][k] = min(adj[j][k], adj[j][b-1]+c+adj[a-1][k]);
                        adj[j][k] = min(adj[j][k], adj[j][a-1]+c+adj[b-1][k]);
                    }
                }
        }

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                ans+=adj[i][j];
            }
        }
        cout<<ans<<" ";
    }
}