#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        int m,n;
        cin>>m>>n;
        map<int,int>mp;
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            mp[a]++;
        }
        int dp[n][10];
        memset(dp,0,sizeof dp);

        for(int i=0;i<n;i++){
            for(int j=1;j<=9;j++){
                if(i==0){
                    dp[i][j]=mp[j];
                    continue;

                }
                if(mp[j]==0)continue;
                dp[i][j]+=dp[i-1][j];
                if(j==1){
                    dp[i][j]+=dp[i-1][2]+dp[i-1][3];
                    continue;
                }
                if(j==2){
                    dp[i][j]+=dp[i-1][1]+dp[i-1][3]+dp[i-1][4];
                    continue;
                }
                if(j==9){
                    dp[i][j]+=dp[i-1][8]+dp[i-1][7];
                    continue;
                }
                if(j==8){
                    dp[i][j]+=dp[i-1][7]+dp[i-1][6]+dp[i-1][9];
                    continue;
                }
                dp[i][j]+=dp[i-1][j-2]+dp[i-1][j-1]+dp[i-1][j+1]+dp[i-1][j+2];
            }
        }
        int sum=0;
        for(int i=1;i<=9;i++){
            sum+=dp[n-1][i];
            //cout<<dp[n-2][i]<<endl;
        }
        cout<<"Case "<<tt+1<<": "<<sum<<"\n";
    }
}
