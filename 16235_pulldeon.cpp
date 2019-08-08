#include <iostream>
#include <cstdio>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;

deque<int> a[11][11];
int ro[11][11]={0,};
int nour[11][11]={0,};
const int dx[8] = { -1,0,+1,-1,+1,-1,0,+1 };
const int dy[8] = { -1,-1,-1,0,0,+1,+1,+1 };

typedef struct _dead{
    int r,c;
    int no;
} d;

int main(){
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            scanf("%d",&ro[r][c]);
            nour[r][c]=5;
        }
    }

    for(int i=0;i<m;i++){
        int r,c,ag; scanf("%d%d%d",&r,&c,&ag);
        r--;c--;
        a[r][c].push_back(ag);
    }
    while(k--){
        deque<d> dt;
        deque< pair<int,int> > make;
        //spring
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                deque<int>& dq = a[r][c];
                if(dq.empty()) continue;
                sort(dq.begin(),dq.end());
                deque<int> nq;
                while(!dq.empty()){
                    if(dq.front()<=nour[r][c]){
                        nour[r][c]-=dq.front();
                        dq.front()++;
                        if(dq.front()%5==0) make.push_back({r,c});
                        nq.push_back(dq.front());
                    }else{
                        d tempd;
                        tempd.r=r;tempd.c=c;
                        tempd.no=dq.front()/2;
                        dt.push_back(tempd);
                    }
                    dq.pop_front();
                    
                }
                dq=nq;
            }
        }

        //summer

        for(int i =0;i<dt.size();i++){
            d& tt = dt[i];
            nour[tt.r][tt.c]+=tt.no;
        }
        //fall
        for(int i =0;i<make.size();i++){
           int rr= make[i].first, cc=make[i].second;
           for(int j =0;j<8;j++){
               
               int ddy = rr+dy[j];
               int ddx = cc+dx[j];
               if(ddy<0||ddy>n||ddx<0||ddx>n)continue;
               a[ddy][ddx].push_back(1);
           } 
        }
        //winter
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                nour[r][c]+=ro[r][c];
            
            }
        }
    }
    int ans = 0;
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            ans += a[r][c].size();
        }
    }
    printf("%d",ans);
    return 0;
}
