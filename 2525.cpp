#include <cstdio>
int main(){
    int h,m,c;scanf("%d%d%d",&h,&m,&c);
    int hh=c/60,mm=c%60;
    h+=hh;m+=mm;
    h+=m/60;
    m%=60;
    h%=24;
    printf("%d %d",h,m);
}