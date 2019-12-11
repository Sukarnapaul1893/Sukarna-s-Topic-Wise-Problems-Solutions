#include<bits/stdc++.h>

using namespace std;

int carry[40000025];
set<int>ans;
void query(int at, int L, int R, int l, int r){

    if(carry[at]){
        //cout<<L<<" "<<R<<"\n";
        ans.insert(carry[at]);
        return;
    }

    if(L==R)return;
    int mid = (L+R)/2;
    query(at*2,L,mid,l,r);
    query(at*2+1,mid+1,R,l,r);
}

void update(int at, int L, int R, int l, int r, int q ){

    if(L>r || R<l)return ;
    if(l<=L && r>=R){
        carry[at]=q;
        return ;
    }
    if(L==R)return;
    int mid = (L+R)/2;
    if(carry[at]){
        carry[at*2]=carry[at];
        carry[at*2+1]=carry[at];
    }
    carry[at]=0;

    update(at*2,L,mid,l,r,q);
    update(at*2+1,mid+1,R,l,r,q);
}

void build(int at , int L, int R){
    carry[at]=0;
    if(L==R){

        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    //getchar();
    for(int tt=0;tt<t;tt++){

        int n;
        n=10000003;

        build(1,1,n);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int I,J;
            cin>>I>>J;
            update(1,1,n,I,J,i+1);
        }
        query(1,1,n,1,n);
        cout<<ans.size()<<"\n";

        ans.clear();
        memset(carry,0,sizeof carry);
    }
}
