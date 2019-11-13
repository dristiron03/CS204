 
#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
#define endl "\n"
using namespace std;


const int N=1023;
const int INF =1000000007;
vector<vector<int>> hashvec(N,vector<int>(1,INF));
int hash_fun(int val){
	return val%N;
}
void insert(int key){
	int hkey=hash_fun(key);
	if(hashvec[hkey].size()==1 && hashvec[hkey][0]==INF){
		hashvec[hkey][0]=key;
	}
	else{
		hashvec[hkey].push_back(key);
	}

}
bool search(int key){
	int hkey=hash_fun(key);
	if(hashvec[hkey].size()==1 && hashvec[hkey][0]==INF) return false;
	
	for(int i=0;i<hashvec[hkey].size();i++){
		
		if(hashvec[hkey][i]==key){
			
			return true;
		}
	
	}
	return false;
}
bool delete_key(int key){
	if(!search(key)) return false;
	int hkey=hash_fun(key);
	
	int i=0;
	for (;i<hashvec[hkey].size();i++) {
		if(hashvec[hkey][i]==key) break;
	}
	if(i==hashvec[hkey].size()) return false;
	hashvec[hkey].erase(hashvec[hkey].begin()+i);
	return true;
}


int main(){
	insert(9214);
	insert(9041274);
	insert(4000);
	insert(1000);
	delete_key(1000);
	if(search(4000)) cout<<"found";
	else cout<<"not found";

	return 0;
}