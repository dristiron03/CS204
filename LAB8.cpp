#include<bits/stdc++.h>
#define ll long long
using namespace std; 
ll partition(double arr[], ll l, ll r, double k); 
double findMedian(double arr[], ll n) 
{ 
    sort(arr, arr+n);
    return arr[n/2];   
}  
  
double kthSmallest(double arr[], ll l, ll r, ll k) 
{ 
    if (k > 0 && k <= r - l + 1) 
    { 
        ll n = r-l+1,i; 
        double median[(n+4)/5];
        for (ll i=0; i<n/5; i++) 
            {
                median[i] = findMedian(arr+l+i*5, 5); 
            }
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
        double medOfMed = (i == 1)? median[i-1]: kthSmallest(median, 0, i-1, i/2); 
        ll pos = partition(arr, l, r, medOfMed); 

        if (pos-l == k-1) 
           {return arr[pos];}
        if (pos-l > k-1) 
            return kthSmallest(arr, l, pos-1, k); 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
} 
  
void swap(double *a, double *b) 
{ 
    double temp = *a; 
    *a = *b; 
    *b = temp; 
} 

ll partition(double arr[], ll l, ll r, double x) 
{ 
    ll i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
    i = l; 
    for (ll j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 

    swap(&arr[i], &arr[r]); 

    return i; 
} 

int main() 
{ 
    ll t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        ll x,y;
        double d[k];
        for(ll i=0;i<k;i++)
        {
            cin>>x>>y;
            d[i]=sqrt(x*x+y*y);
        }
        cout<<kthSmallest(d, 0, k-1, (k+1)/2)<<endl;
    }
    return 0; 
}