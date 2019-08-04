#include<bits/stdc++.h>
using namespace std;
void print(string s1, string s2){
    if(s2.size() > s1.size()){//check=true;
        string s=s1;
        s1=s2;
        s2=s;
    }else if(s2 > s1 && s2.size() == s1.size()){
        //check=true;
        string s=s1;
        s1=s2;
        s2=s;
    }
    if(s2.size()<s1.size()){
        for(int i=s2.size(); i<s1.size(); i++){
            s2 = '0'+s2;
        }
    }
    //cout<<s1<<" "<<s2<<endl;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    vector<int>v(0);
    int carry =0;
    for(int i=0; i<s1.size(); i++){
        int a = s1[i]-'0';
        int b = s2[i]-'0'+carry;
        if(a<b){
            a+=10;
            v.push_back(a-b);
            carry =1;
        }
        else{
            v.push_back(a-b);
            carry=0;
        }
    }
    //int a = s1[s1.size()-1]-'0';
    //int b = s2[s2.size()-1]-'0'+carry;
    //cout<<a-b;
    //if(check){cout<<'-';}
    reverse(v.begin(), v.end());
    bool check2 =false;
    for(int i=0; i<v.size(); i++){
        if(v[i] != 0){check2=true;}
        else if(v[i]== 0 && !check2){continue;}
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
