#include <cstdio>
#include <algorithm>
int main(){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    printf("%d",std::max(c-b-1,b-a-1));
}