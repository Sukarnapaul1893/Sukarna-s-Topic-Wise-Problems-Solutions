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

int check_prime(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            return 0;
        }

    }
    return 1;
}

void recursion(vector<int> s,int n){

    set<int>st;
    for(int i =1;i<=n;i++){
        st.insert(i);
    }
    for(int i=0;i<s.size();i++){
        st.erase(s[i]);
    }
    for(auto it=st.begin();it!=st.end();it++){
        int a = (*it);
        int b = s[s.size()-1];
        if(check_prime(a+b)==1 ){

            vector<int>newstring;
            for(int i=0;i<s.size();i++){
                newstring.pb(s[i]);
            }
            newstring.pb((*it));
            if(newstring.size()==n){
                if(check_prime(1+a)==1){
                    for(int i=0;i<newstring.size();i++){
                        cout<<newstring[i];
                        if(i+1!=newstring.size()){
                            cout<<" ";
                        }
                    }
                    cout<<"\n";
                }

                continue;
            }
            recursion(newstring , n );
        }


    }

}

int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int n;
    int c=1;
    bool bl = true;
    while(cin>>n){
        if(bl==false){
            cout<<"\n";
        }
        bl=false;
        vector<int>vec;
        vec.pb(1);
        cout<<"Case "<<c++<<":\n";
        recursion(vec,n);

    }


}
