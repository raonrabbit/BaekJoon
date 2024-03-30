#include<stdio.h>
#include<limits.h>
#include <algorithm>
using namespace std;

int minCount = INT_MAX;
void dp(int n, int count) {
	if (n == 1) {
		minCount = minCount > count ? count : minCount;
		return;
	}
	if (n < 0 || count > minCount) return;
	int a = INT_MAX, b = INT_MAX, c = INT_MAX;
	count++;
	if (n % 3 == 0) dp(n / 3, count);
	if (n % 2 == 0) dp(n / 2, count);
	dp(n - 1, count);
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	dp(n, 0);
	printf("%d", minCount);
}