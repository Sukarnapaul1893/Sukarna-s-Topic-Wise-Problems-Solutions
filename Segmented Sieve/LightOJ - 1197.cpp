#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
int arr[1000006],mark[1000006];
vector<ll >prime;
bitset <10000010> bs;

void sieve (int n){
	bs.set ();
	for (int i = 2; i <= n; i++){
		if (bs[i])prime.pb(i);
		for (int j = 0; j<prime.size() && i*prime[j]<=n; j++){
		    bs[i*prime[j]] = 0;
		    if(i%prime[j]==0)break;
		}
	}
}
void Segmented_Sieve(ll low , ll high){
    for(ll i=0;prime[i]*prime[i]<=high;i++){

        int start = (((low-1)/prime[i]+1))*prime[i];
        if(start==prime[i])start+=prime[i];
        for(ll j=start ; j<=high ; j+=prime[i]){
            mark[j-low]=1;
        }
        if(low==1)mark[0]=1;
    }
}

int main(){
    //IOS
    sieve(1000002);
    int t;  cin>>t;
    int test =1;
    while(t--){
        int low , high; cin>>low>>high;
        memset(mark,0,sizeof mark);
        int freq=0;

        if(high<2){
            cout<<"Case "<<test++<<": "<<0<<"\n";
            continue;
        }
        if(low<2)low=2;
        Segmented_Sieve(low,high);
        for(int i=low ;i<=high; i++){
            if(mark[i-low]==0){
                freq++;
            }
        }cout<<"Case "<<test++<<": "<<freq<<"\n";
    }
}
