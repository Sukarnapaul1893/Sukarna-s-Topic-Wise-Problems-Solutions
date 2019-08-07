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
int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        string s;
        cin>>s;
        int n=s.length();
        ll dp[n][3];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='W'){
                    dp[i][0]=1;
                    dp[i][1]=1;
                    dp[i][2]=1;
                }
                else if(s[i]=='R')dp[i][0]=1;
                else if(s[i]=='G')dp[i][1]=1;
                else if(s[i]=='B')dp[i][2]=1;

            }
            else if(s[i]=='W'){
                if(s[i-1]!='R')dp[i][0]+=dp[i-1][1]+dp[i-1][2];
                if(s[i-1]!='G')dp[i][1]+=dp[i-1][0]+dp[i-1][2];
                if(s[i-1]!='B')dp[i][2]+=dp[i-1][0]+dp[i-1][1];
            }
            else{
                if(s[i]=='R')dp[i][0]+=dp[i-1][1]+dp[i-1][2];
                if(s[i]=='G')dp[i][1]+=dp[i-1][0]+dp[i-1][2];
                if(s[i]=='B')dp[i][2]+=dp[i-1][0]+dp[i-1][1];
            }
            dp[i][0]%=1000000007;
            dp[i][1]%=1000000007;
            dp[i][2]%=1000000007;
        }
        cout<<"Case "<<tt+1<<": ";
        cout<<(dp[n-1][0]+dp[n-1][1]+dp[n-1][2])%1000000007<<"\n";
    }
}
