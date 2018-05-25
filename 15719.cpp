#include<cstdio>
typedef long long LL;
int main() {
	LL n,m,s=0,k;scanf("%lld", &n);k=n;
	while (n--) {scanf("%lld", &m); s += m;}
	printf("%lld", s-(k*(k-1)/2));
	return 0;
}