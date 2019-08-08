#include <cstdio>
#include <cmath>
#include <boost/multiprecision/float128.hpp>

namespace boost{ namespace multiprecision{

class float128_backend;

typedef number<float128_backend, et_off>    float128;

}} // namespaces

const double ep = 1e-11;
int main(){
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    float128 mn=0, mx=1.0*a*(float128)c+(float128)a;
    while(mx-mn>=ep){
        float128 mid=(mx+mn)/2;
        (a*mid+b*sin(mid)<c?mn:mx)=mid;
    }
    printf("%.8lf\n",mn);
    return 0;
}
