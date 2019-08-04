#include<bits/stdc++.h>
using namespace std;
string add(string s1, string s2){
    int carry=0;
    string ans = "";
    if(s1.size() < s2.size()){
        string ss;
        ss=s1;
        s1=s2;
        s2=ss;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for(int i = 0; i< s2.size(); i++){
        int sum = s1[i]-'0'+s2[i]-'0'+carry;
        ans+=sum%10+'0';
        carry=sum/10;
    }
    //int j=min(s1.size(), s2.size());
    for(int i = s2.size(); i<s1.size(); i++){
        int sum = s1[i]-'0'+carry;
        ans+=sum%10+'0';
        carry = sum/10;
    }
    if(carry){ans+= carry+'0';}
    reverse(ans.begin(), ans.end());
    return ans;
}

string print(string s1, string s2){
    if(s1.size()< s2.size()){
        string ss;
        ss=s1;
        s1=s2;
        s2=ss;
    }
    string ans="0";
    reverse(s2.begin(), s2.end());
    string digits[10];
    for(int i=1; i<10; i++){
        for(int j=1; j<= i; j++){
            digits[i] = add(digits[i], s1);
        }
    }
    string aa = "";
    for(int i=0; i<s2.size(); i++){
        string zz = digits[s2[i]-'0'];
        zz += aa;
        ans = add(ans, zz);
        aa += "0";
    }
    //reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        //cout<<add(s1,s2)<<endl;
        cout<<print(s1, s2)<<endl;
    }

}
