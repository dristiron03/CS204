#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
        int users, queries;
        cin>>users>>queries;
        int inp[queries][3] = {0};
        int id[queries]={0};
        for(int i=0; i<queries; i++){
            cin>>inp[i][0];
            if(inp[i][0] == 1){
                cin>>inp[i][1]>>inp[i][2];
                id[i] = inp[i][1];
            }  
        }
        int freq[queries] = {0};
        bool check=false; int maxi; int val=-1;
        sort(id, id+queries);
        for(int i=0; i<queries; i++){
            if(inp[i][0] == 1){
                int temp = lower_bound(id, id+queries, inp[i][1])-id;
                freq[temp] += inp[i][2];
                if(freq[temp] > val){
                    val = freq[temp];
                    check = true;
                    maxi = inp[i][1];
                }
            }
            else{
                if(check){
                    cout<<maxi<<endl;
                }
                else{
                    cout<<"No data available\n";
                }
            }
        }


    
}