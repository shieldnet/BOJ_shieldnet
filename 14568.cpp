#include <cstdio>
int main(){
    int n,ans=0; scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(i==0||j==0||k==0)continue;
                if(i%2==1)continue;
                if(k-j<2)continue;
                if((i+j+k)!=n)continue;
                ans++;
            }
        }
    }
    printf("%d",ans);
}