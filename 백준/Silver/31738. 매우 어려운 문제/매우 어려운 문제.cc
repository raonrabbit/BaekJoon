#include<stdio.h>
long long cal(long long n, long long m) {
	long long r = 1;
	for (long long i = 2; i <= n; i++) {
		r *= i;
		r %= m;
	}
	return r;
}
int main() {
	long long N, M;
	scanf("%lld %lld", &N, &M);

	if (N >= M) printf("0");
	else printf("%lld", cal(N, M));
}