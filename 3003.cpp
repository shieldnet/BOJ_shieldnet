#include <cstdio>
int main(){
    int ch[6]={1,1,2,2,2,8};
    for(int i =0;i<6;i++){
        int m;scanf("%d",&m);
        printf("%d ",ch[i]-m);
    }
}