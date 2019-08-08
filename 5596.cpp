#include <cstdio>
#include <algorithm>
int main(){
    int s=0,t=0,tt;
    for(int i=0;i<4;i++){
        scanf("%d",&tt); s+=tt;
    }
    for(int i=0;i<4;i++){
        scanf("%d",&tt); t+=tt;
    }
    printf("%d",std::max(s,t));
    return 0;
}