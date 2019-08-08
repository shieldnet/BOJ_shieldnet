#include <cstdio>

const int mod = 10007;
int dp[10][1001]={0,};
int main(){
    for(int i =0;i<10;i++){
        dp[i][1]=1;
    }
    int n;scanf("%d",&n);
    for(int i =2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                dp[j][i]+=dp[k][i-1];
                dp[j][i]%=mod;
            }
        }
    }
    int ans =0;

    for(int i =0;i<10;i++){
        ans+=dp[i][n];
        ans%=10007;
    }
    printf("%d",ans);

    
    return 0;
}