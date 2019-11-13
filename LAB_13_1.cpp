#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector<string> v;
    vector<string> b;
    while(n--)
    {
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        if(s!=t)
        {
            v.push_back(s);
            b.push_back(t);
        }
    }
    sort(b.begin(),b.end());
    for(auto s:v)
    {
        if(binary_search(b.begin(),b.end(),s))
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}