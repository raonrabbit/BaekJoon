#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> dp(41, 0);
int fibonacci(int n) {
    if (n == 0) {
        dp[0] = 0;
        return 0;
    }
    else if (n == 1) {
        dp[0] = 0;
        dp[1] = 1;
        return 1;
    }
    else {
        if (dp[n] > 0) return dp[n];
        else dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return dp[n];
    }
}

int main() {
	int n, t;
	scanf("%d", &n);
    int al[100], bl[100];
	for (int i = 0; i < n; i++) {
        fill(dp.begin(), dp.end(), 0);
        scanf("%d", &t);
        if (t == 0) {
            al[i] = 1;
            bl[i] = 0;
            continue;
        }
        fibonacci(t);
        al[i] = dp[t - 1];
        bl[i] = dp[t];
	}

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", al[i], bl[i]);
    }
}