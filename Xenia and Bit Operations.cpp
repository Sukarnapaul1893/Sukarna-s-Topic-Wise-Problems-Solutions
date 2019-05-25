#include<bits/stdc++.h>

using namespace std;

int sum[400020];
int arr[200005];
int state;
int query(int at, int L, int R, int l, int r){
    if(r<L || R<l)return 0;

    if(l<=L && R<=r)return sum[at];

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r);
    int y = query(at*2+1,mid+1,R,l,r);

    return (x+y);
}

void update(int at, int L, int R, int pos, int u ){
    if(L==R){
        sum[at]=u;
        state = 1;
        return ;
    }

    int mid = (L+R)/2;

    if(pos<=mid){
        update(at*2,L,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,R,pos,u);
    }
    if(state==0){
        state = 1;
    }
    else{
        state = 0;
    }
    if(state==0){
        sum[at] = sum[at*2] | sum[at*2+1];
    }
    else{
        sum[at] = sum[at*2] ^ sum[at*2+1];
    }
}

void build(int at , int L, int R){
    sum[at]=0;
    if(L==R){
        sum[at]=arr[L];
        state =1;
        return;
    }
    int mid = (L+R)/2;

    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
    if(state==0){
        state = 1;
    }
    else{
        state = 0;
    }
    if(state==0){
        sum[at] = sum[at*2] | sum[at*2+1];
    }
    else{
        sum[at] = sum[at*2] ^ sum[at*2+1];
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;


    for(int i=1;i<=pow(2,n);i++){
        cin>>arr[i];
    }
    build(1,1,pow(2,n));
    /*for(int i=1;i<=4*pow(2,n);i++){
        cout<<sum[i]<<"\n";
    }*/


    for(int i=0;i<m;i++){

        int p,b;
        cin>>p>>b;
        update(1,1,pow(2,n),p,b);


        cout<<sum[1]<<"\n";
    }


}
