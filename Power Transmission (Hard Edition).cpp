#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    double x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    set<pair<int,int> >st;
    map<pair<int,int> ,set<int> >mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x1 = x[i];
            int x2 = x[j];
            int y1 = y[i];
            int y2 = y[j];
            int a = y1-y2;
            int b = x1-x2;

            int g = __gcd(a,b);
            a/=g;
            b/=g;
            if (a < 0 || (a == 0 && b < 0))
			{
			    a = -a;
			    b = -b;
			}
            int c = a*x1 - b*y1;

            mp[{a,b}].insert(c);
        }
    }
    int cnt=0;
    long long total = 0;

    long long ans = 0;
    for(auto it=mp.begin();it!=mp.end();it++){
        total += 1LL*(*it).second.size();
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        ans += 1LL*(*it).second.size()*(total-(*it).second.size());
    }

    cout<<ans/2LL;
}
