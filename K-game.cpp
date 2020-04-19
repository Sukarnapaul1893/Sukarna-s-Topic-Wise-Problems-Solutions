//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

ll arr[100005];
ll pre[100005];


ll ans [100317][317][2];

void build(int n){
    for(int i=n;i>=1;i--){

        for(int k=1;k<=sqrt(n);k++){
            ans[i][k][0]=ans[i+k][k][1]+pre[min(n,i+k-1)]-pre[i-1];
            ans[i][k][1]=ans[i+k][k][0];
        }
    }
}


int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i==1){
            pre[i]=arr[i];
        }
        else{
            pre[i]=pre[i-1]+arr[i];
        }
    }

    build(n);



    int sq = sqrt(n);
    for(int ii=0;ii<q;ii++){
        int p,k;
        cin>>p>>k;
        if(k<=sq){
            ll ans1 = ans[p][k][0];
            ll ans2 = ans[p][k][1];
            //cout<<ans1<<" "<<ans2<<"\n";
            if(ans1>ans2){
                cout<<"Tom\n";
            }
            else if(ans2>ans1){
                cout<<"Jerry\n";
            }
            else{
                cout<<"Tied\n";
            }
        }
        else{
            ll ans1 = 0;
            ll ans2 = 0;
            bool bl =false;
            int x = p;
            for(int i=x;i<=n;i+=k){
                if(bl==false){
                    ans1+=pre[min(n,i+k-1)]-pre[i-1];
                    bl=true;
                }
                else {
                    ans2+=pre[min(n,i+k-1)]-pre[i-1];
                    bl=false;
                }
            }
            //cout<<ans1<<" "<<ans2<<"\n";
            if(ans1>ans2){
                cout<<"Tom\n";
            }
            else if(ans2>ans1){
                cout<<"Jerry\n";
            }
            else{
                cout<<"Tied\n";
            }
        }
    }
}
