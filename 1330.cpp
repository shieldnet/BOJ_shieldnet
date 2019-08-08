#include <cstdio>
int main(){
    int a,b;scanf("%d%d",&a,&b);
    printf("%s",a>b?">":(a==b)?"==":"<");
}