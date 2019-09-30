#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<ll, ll> >points;
ll orient(pair<ll, ll>p, pair<ll, ll> q, pair<ll, ll>r){
    ll sum = (q.first*r.second)-(q.second*r.first)+p.second*(r.first-q.first)+p.first*(q.second-r.second);
    return sum;
}
vector<pair<ll, ll> >ans;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;
        points.push_back({x, y});
    }
    sort(points.begin(), points.end());
    pair<ll, ll>p1 = points[0];
    pair<ll, ll>p2 = points.back();
    vector<pair<ll, ll> >up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(ll i=0; i<(ll)points.size(); i++){
        if(i == points.size()-1 || orient(p1, points[i], p2) < 0){
            while(up.size() >= 2 && orient(up[up.size()-2], up[up.size()-1], points[i]) >= 0){
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        if(i == points.size()-1 || orient(p1, points[i], p2) > 0){
            while(down.size() >= 2 && orient(down[down.size()-2], down[down.size()-1], points[i]) <= 0){
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }

    for(ll i=0; i< (ll)up.size(); i++){
        ans.push_back(up[i]);
    }
    for(ll j=down.size()-2; j> 0; j--){
        ans.push_back(down[j]);
    }
    cout<<ans.size()<<endl;
    for(ll j=0; j<ans.size(); j++){
        cout<<ans[j].first<<" "<<ans[j].second<<endl;
    }
}