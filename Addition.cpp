//Addition of two numbers
//Irrespective of number size, the code successfully outputs the required sum.
//Time complexity -> O(n) || n -> Number of digts

#include<bits/stdc++.h>
using namespace std;
void print(string s1, string s2){
    int carry=0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    vector<int>v(0);
    for(int i=0; i<min(s1.size(), s2.size()); i++){
        int a = s1[i]-'0'+s2[i]-'0'+carry;
        v.push_back(a%10);
        carry = a/10;
    }
    int j= min(s1.size(), s2.size());
    if(s1.size() > s2.size()){
        for(int i = j; i<s1.size(); i++){
            int a = s1[i]-'0'+carry;
            v.push_back(a%10);
            carry = a/10;
        }
    }
    else if(s2.size() > s1.size()){
        for(int i = j; i<s2.size(); i++){
            int a = s2[i]-'0'+carry;
            v.push_back(a%10);
            carry = a/10;
        }
    }
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
}

int main(){
    long long t;
    cin>>t;
    while(t--){
    string s1, s2;
    cin>>s1>>s2;
    print(s1, s2);
    cout<<"\n";
    }

}
