#include <cstdio>
int main(){
    int s1,s2;scanf("%d%d",&s1,&s2);
    bool sam=true,sys=true;
    for(int i =0;i<s1;i++){
        int a,b;scanf("%d%d",&a,&b);
        if(a!=b){
            sam=false;
        }
    }
    for(int i =0;i<s2;i++){
        int a,b;scanf("%d%d",&a,&b);
        if(a!=b){
            sys=false;
        }
    }
    if(!sam) printf("Wrong Answer");
    else if(sam&&!sys)printf("Why Wrong!!!");
    else{
        printf("Accepted");
    }
}