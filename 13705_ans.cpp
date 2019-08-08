#include <cstdio>
#include <math.h>
using namespace std;
int main() {
    int a, b, c; 
    scanf("%d %d %d", &a, &b, &c); 
    long double to = (c - b) / (double)a;
    long double des = (c + b) / (double)a;
    long double mid; int stopper = 50000; 
    while (to < des && stopper--) {
        mid = (des + to) / 2; 
        if (mid > (c - (b * (long double)sin(mid))) / a) des = mid; 
        else if ( mid < (c - (b * (long double)sin(mid))) / a) to = mid + 0.00000000000000000001; 
    }

    printf("%.6Lf\n", mid);
    return 0;
}
