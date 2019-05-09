#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        int n;
        cin>>n;
        int r[n],g[n],b[n];

        for(int i=0;i<n;i++){

            cin>>r[i]>>g[i]>>b[i];
        }
        for(int i=n-2;i>=0;i--){
            r[i]+=min(g[i+1],b[i+1]);
            g[i]+=min(r[i+1],b[i+1]);
            b[i]+=min(r[i+1],g[i+1]);
        }
        cout<<"Case "<<tt+1<<": "<<min(min(g[0],b[0]),r[0])<<"\n";
    }
}
