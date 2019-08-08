#include<cstdio>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    c%=2;
    for(int i =0;i<c;i++)a^=b;
    printf("%d",a);
}