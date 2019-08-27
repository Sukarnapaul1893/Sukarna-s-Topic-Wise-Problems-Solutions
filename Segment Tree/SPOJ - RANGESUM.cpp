#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
#define mset(a,b) memset(a,b,sizeof(a))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll sum[800020];
ll arr[200005];

ll query(int at, int L, int R, int l, int r){
    if(r<L || R<l)return 0;

    if(l<=L && R<=r)return sum[at];

    int mid = (L+R)/2;

    ll x = query(at*2,L,mid,l,r);
    ll y = query(at*2+1,mid+1,R,l,r);

    return (x+y);
}

void update(int at, int L, int R, int pos, ll u ){
    if(L==R){
        sum[at]+=u;
        return ;
    }

    int mid = (L+R)/2;

    if(pos<=mid){
        update(at*2,L,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,R,pos,u);
    }

    sum[at] = sum[at*2] + sum[at*2+1];
}

void build(int at , int L, int R){
    sum[at]=0;
    if(L==R){
        sum[at]=arr[L];
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    sum[at] = sum[at*2] + sum[at*2+1];

}

int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int N=200004;
    for(int i=n;i>=1;i--){
        cin>>arr[i];
    }
    for(int i=n+1;i<=N;i++)arr[i]=0;
    build(1,1,N);

    int q;
    cin>>q;
    int cur=n+1;
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        //cout<<cur<<"\n";
        if(type==2){
            ll x;
            cin>>x;
            update(1,1,N,cur++,x);
        }
        else{
            int L,R;
            cin>>L>>R;
            cout<<query(1,1,N,cur-R,cur-L)<<"\n";
        }
    }


}
