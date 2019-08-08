#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cstring>
using namespace std;
#define sci(n) scanf("%lld", &(n))
#define scd(n) scanf("%Ld", &(n))
typedef long long LL;
typedef vector<LL> VLL;
typedef long double LD;
typedef pair<LL,LL> pll;

//Matrix a(n by m), Matrix b(m by l), result Matrix c(n by l)
typedef vector< VLL > matrix;
const LL mod =  31991;

matrix operator* (const matrix &a, const matrix &b) {
    int n = a.size(), m = a[0].size(), l = b[0].size();
    matrix c(n, vector<long long>(l));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<l; j++) {
            for (int k = 0; k<m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod; //If not need = erase;
        }
    }
    return c;
}

int main(void) {

    int n; cin>>n;
    while(n--){
        matrix v =
        {
            {1,0,0,0,1},
            {0,1,0,0,0},
            {0,0,1,0,0},
            {0,0,0,1,0},
            {0,0,0,0,1}
        };
        matrix ans =
        {
            {1,0,0,0,0},
            {0,1,0,0,0},
            {0,0,1,0,0},
            {0,0,0,1,0},
            {0,0,0,0,1}
        };
       

        int k; cin>>k;
        k-=5;
        while (k > 0) {
            if (k % 2 == 1) {
                ans = ans * v;
            }
            v = v * v;
            k /= 2;
        }
         
        for(int i =0;i<5;i++){
            for(int j =0;j<5;j++){
                cout << ans[i][j] << " ";
            }
            puts("");
        }


        vector<int> pado = {2,2,1,1,1};
        long long a = 0;
        for(int i =0;i<n;i++){
            a+=pado[i]*ans[0][i];
        }
        cout << a << "\n";

    }

    return 0;
}
