#include<bits/stdc++.h>

using namespace std;
int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position
       k%n + 1 as position 1 */
    return (josephus(n - 1, k) + k-1) % n + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        int n,k;
        cin>>n>>k;
        cout<<"Case "<<tt+1<<": "<<josephus(n,k);
        cout<<"\n";
    }
}
