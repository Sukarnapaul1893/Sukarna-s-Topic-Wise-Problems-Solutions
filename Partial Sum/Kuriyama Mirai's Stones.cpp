#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    ll arr[n],arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr2[i]=arr[i];
    }
    sort(arr2,arr2+n);

    for(int i=0;i<n;i++){
        if(i==0)continue;
        arr[i]+=arr[i-1];
    }
    for(int i=0;i<n;i++){
        if(i==0)continue;
        arr2[i]+=arr2[i-1];
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int t,l,r;
        cin>>t>>l>>r;

        if(t==1){
            if(l==1){
                cout<<arr[r-1]<<"\n";
                continue;
            }
            cout<<arr[r-1]-arr[l-2]<<"\n";
        }
        else{
            if(l==1){
                cout<<arr2[r-1]<<"\n";
                continue;
            }
            cout<<arr2[r-1]-arr2[l-2]<<"\n";
        }
    }
}
