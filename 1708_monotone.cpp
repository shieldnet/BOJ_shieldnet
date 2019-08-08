#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>

#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


pii operator-(pii a, pii b){ return {a.x-b.x, a.y-b.y}; }
ll cross(pii a, pii b){ return b.y*1LL*a.x - b.x*1LL*a.y; }
bool ccw(pii a, pii b, pii c){ return cross(b-a, c-a) >= 0; }

pair<vector<pii>, vector<pii> > ConvexHull(vector<pii> pt){
    sort(pt.begin(),pt.end());
    vector<pii> uhl,dhl;
    int un=0,dn=0;
    for(int i=0;i<pt.size();i++){
        while(un>=2 && ccw(uhl[un-2],uhl[un-1],pt[i])){
            uhl.pop_back(), un--;
        }
        uhl.push_back(pt[i]);
        un++;
    }
    reverse(pt.begin(),pt.end());
    for(int i =0;i<pt.size();i++){
        while(dn>=2 && ccw(dhl[dn-2],dhl[dn-1],pt[i])){
            dhl.pop_back(), dn--;
        }
        dhl.push_back(pt[i]); dn++;
    }
    return {uhl,dhl};
}

int main(){
    int n; scanf("%d",&n);
    vector< pii > v;
    for(int i =0;i<n;i++){ pii p; scanf("%d%d",&p.first, &p.second); v.push_back(p);}
    pair<vector<pii>, vector<pii> > ans = ConvexHull(v);
    printf("%d",(int)ans.first.size()+(int)ans.second.size()-2);

    return 0;
}
