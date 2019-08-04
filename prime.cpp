#include<bits/stdc++.h>
using namespace std;
bool isprime(long long n){
    if(n%2 == 0 && n!= 2){return false;}
    if(n%3 == 0 && n!= 3){return false;}
    for(long long i=5; i<= sqrt(n)+1; i+=6){
        if(n%i == 0){return false;}
    }
    return true;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if(isprime(n)){cout<<"Prime\n";}
        else{cout<<"Not Prime\n";}
    }
    return 0;
}
