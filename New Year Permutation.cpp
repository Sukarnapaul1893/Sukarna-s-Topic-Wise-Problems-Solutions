#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
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


int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    char arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][k]=='1' && arr[k][j]=='1'){
                    arr[i][j]='1';
                }
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i][j]=='1' && p[i]>p[j]){
                int t = p[i];
                p[i]=p[j];
                p[j]=t;

            }
        }
    }


    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
}
