#include<cstdio>
int main(){
    for(int i=0;i<3;i++){
        int a,b,c,d,e,f;scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        int before=a*3600+b*60+c;
        int after=d*3600+e*60+f;
        after-=before;
        int x=after/3600, y=(after%3600)/60, z=(after%3600)%60;
        printf("%d %d %d\n",x,y,z);
    }
}