#include<bits/stdc++.h>
using namespace std;
void solve(string s){
    stack<char>sr;
    for(long long i =0; i<s.size(); i++){
        if(s[i] == '|'){
            //cout<<"!"<<endl;
            if(!sr.empty() && sr.top() == '|'){
                sr.pop();
            }
            else{
                sr.push(s[i]);
            }
        }
        else if(s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<'){
            sr.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!sr.empty() && sr.top() == '('){
                sr.pop();
            }
            else{
                cout<<"NO\n";
                return ;
            }
        }
        else if(s[i] == '}'){
            if(!sr.empty() && sr.top() == '{'){
                sr.pop();
            }
            else{
                cout<<"NO\n";
                return ;
            }
        }
        else if(s[i] == ']'){
            if(!sr.empty() && sr.top() == '['){
                sr.pop();
            }
            else{
                cout<<"NO\n";
                return ;
            }
        }
        else if(s[i] == '>'){
            if(!sr.empty() && sr.top() == '<'){
                sr.pop();
            }
            else{
                cout<<"NO\n";
                return ;
            }
        }
    }
    if(sr.empty()){cout<<"YES\n";}
    else{cout<<"NO\n";}
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        solve(s);
    }
}