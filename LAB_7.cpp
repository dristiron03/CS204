#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
bool compare(string a, string b){
    long long x = a.size();
    long long y = b.size();
    if(x<y){
        for(long long i=0; i<x;i++){
            if(a[i] < b[i]){return true;}
            else if(b[i] < a[i]){return false;}
        }
        for(long long i=x; i<y; i++){
            if(b[i]> b[i-x]){return true;}
            else if(b[i-x] > b[i]){return false;}
        }
        return true;
    }
    else{
       for(long long i=0; i<y;i++){
            if(a[i] < b[i]){return true;}
            else if(b[i] < a[i]){return false;}
        }
        for(long long i=y; i<x; i++){
            if(a[i]> a[i-y]){return false;}
            else if(a[i-y] > a[i]){return true;}
        }
        return true; 
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
 
    long long n;
    cin>>n;
    while(n--){
        long long t;
        cin>>t;
        string ar[t];
        for(long long i=0; i<t; i++){
            cin>>ar[i];
        }
        sort(ar, ar+t, compare);
        for(long long i=t-1; i>=0; i--){
            cout<<ar[i];
        }
        cout<<endl;
    }
}
