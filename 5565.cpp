#include <cstdio>
int main(){
    int n=0,a=0;scanf("%d",&a);
    for(int i=0;i<9;i++){
        int temp;scanf("%d",&temp);
        n+=temp;
    }
    printf("%d",a-n);
}