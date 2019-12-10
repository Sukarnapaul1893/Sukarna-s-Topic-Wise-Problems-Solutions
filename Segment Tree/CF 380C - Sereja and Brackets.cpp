#include<bits/stdc++.h>

using namespace std;

int dat[4000020][3];
int arr[1000005];
int lefty;

int query(int at, int L, int R, int l, int r){
    if(r<L || R<l)return 0;

    if(l<=L && R<=r){
        int a = lefty, b=dat[at][2];

        lefty-=min(a,b);
        lefty+=dat[at][1];
        return dat[at][0]+min(a,b)*2;
    }

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r);
    int y = query(at*2+1,mid+1,R,l,r);

    return (x+y);
}

void build(int at , int L, int R){
    //cout<<"\n";
    //cout<<at<<" "<<L<<" "<<R<<" "<<" ";
    if(L==R){

        if(arr[L]==1)dat[at][1]++;
        else if(arr[L]==2)dat[at][2]++;

        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
    int mn = min(dat[at*2][1],dat[at*2+1][2]);
    dat[at][0] += dat[at*2][0]+dat[at*2+1][0] + mn*2;
    dat[at][1] += dat[at*2][1]+dat[at*2+1][1] - mn;
    dat[at][2] += dat[at*2][2]+dat[at*2+1][2] - mn;

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    int n=s.length();
    //arr[0]='-';
    for(int i=1;i<=n;i++){
        if(s[i-1]=='(')arr[i]=1;
        if(s[i-1]==')')arr[i]=2;
    }

    build(1,1,n);

    int q;
    cin>>q;

    for(int ii=0;ii<q;ii++){
        int l,r;
        cin>>l>>r;
        lefty=0;
        cout<<query(1,1,n,l,r)<<"\n";
    }

}
