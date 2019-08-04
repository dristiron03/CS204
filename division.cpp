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
string subtract(string s1, string s2){
    if(s2.size() > s1.size()){
        string s=s1;
        s1=s2;
        s2=s;
    }else if(s2 > s1 && s2.size() == s1.size()){
        string s=s1;
        s1=s2;
        s2=s;
    }
    if(s2.size()<s1.size()){
        for(int i=s2.size(); i<s1.size(); i++){
            s2 = '0'+s2;
        }
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string v="";
    int carry =0;
    for(int i=0; i<s1.size(); i++){
        int a = s1[i]-'0';
        int b = s2[i]-'0'+carry;
        if(a<b){
            a+=10;
            v.push_back(a-b+'0');
            carry =1;
        }
        else{
            v.push_back(a-b+'0');
            carry=0;
        }
    }
    reverse(v.begin(), v.end());
    string ans="";
    bool flag = false;
    for(int i=0; i<v.size(); i++){
        if(v[i] != '0'){flag = true;}
        if(!flag){continue;}
        ans += v[i];
    }
    return ans;
}
bool check(string s1, string s2){
    if(s2.size() < s1.size()){
        return true;
    }else if(s2 <= s1 && s2.size() == s1.size()){
        return true;
    }
    return false;
}
void divide(string s1, string s2){
    if(s2.size() > s1.size()){
        string s=s1;
        s1=s2;
        s2=s;
    }else if(s2 > s1 && s2.size() == s1.size()){
        string s=s1;
        s1=s2;
        s2=s;
    }
    string rem="";
    string ans="";
    int j=0;
    while(1){
        string divisor=s2;
        string dividend = rem;
        bool flag= false;
        if(j == 0){
            for(int i=j; i<s1.size(); i++){
            dividend += s1[i];
            if(check(dividend, divisor)){
                j = i+1;
                flag = true;
                break;
                }
            }
        }
        else{
        for(int i=j; i<s1.size(); i++){
            dividend += s1[i];
            string sm="";
            for(int k =0 ; k<dividend.size(); k++){
                if(dividend[k] == '0' && sm == ""){
                    continue;
                }
                else{sm += dividend[k];}
            }
            dividend = sm;
            if(check(dividend, divisor)){
                j = i+1;
                flag = true;
                break;
            }
            ans += '0';
        }}
        if(dividend == ""){dividend = '0';}
        //cout<<divisor<<" "<<dividend<<endl;
        if(!flag && !check(dividend, divisor)){
            cout<<ans<<"\n"<<dividend<<endl;
            return;
        }
        int jj=0;
        while(check(dividend, divisor)){
            divisor = add(divisor, s2);
            jj++;
        }
        //cout<<divisor<<endl;
        divisor = subtract(divisor, s2);
        rem = subtract(dividend, divisor);
        if(jj != 0){
            ans += jj+'0';
        }

    }
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        //cout<<add(s1, s2)<<endl;
        //cout<<subtract(s1, s2)<<endl;
        divide(s1, s2);
    }

}
