#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

vector<ll>data[120020];
ll arr[30005];

int query(int at, int L, int R, int l, int r,ll k){
    if(r<L || R<l)return 0;

    if(l<=L && R<=r){
        int cnt = upper_bound(data[at].begin(),data[at].end(),k)-data[at].begin();
        return (data[at].size()-cnt);
    }

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r,k);
    int y = query(at*2+1,mid+1,R,l,r,k);

    return (x+y);
}



void build(int at , int L, int R){
    if(L==R){
        data[at].pb(arr[L]);
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
    int i,j;
    for(i=0,j=0;i<data[at*2].size() && j<data[at*2+1].size();){
        if(data[at*2][i]<=data[at*2+1][j]){
            data[at].pb(data[at*2][i]);
            i++;
        }
        else{
            data[at].pb(data[at*2+1][j]);
            j++;
        }
    }
    for(;i<data[at*2].size();i++){
        data[at].pb(data[at*2][i]);
    }
    for(;j<data[at*2+1].size();j++){
        data[at].pb(data[at*2+1][j]);
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;


    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);

    int q;
    cin>>q;
    int last_ans=0;
    for(int i=0;i<q;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        int I = a^last_ans;
        int J = b^last_ans;
        ll K = c^last_ans;

        if(I<1)I=1;
        if(J>n)J=n;
        if(I>J)last_ans=0;
        else last_ans= query(1,1,n,I,J,K);
        cout<<last_ans<<"\n";
    }
}
