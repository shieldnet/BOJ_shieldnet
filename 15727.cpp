#include <cstdio>
int main(){
    long long sum=0,cnt=0,t,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        cnt++;
        sum=+n;
    }
    printf("%lld\n%lld",cnt,sum);
}