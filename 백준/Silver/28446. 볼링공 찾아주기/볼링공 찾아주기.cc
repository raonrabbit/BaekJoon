#include<stdio.h>
#include<unordered_map>

using namespace std;

int main() {
	int n, a, x, w;
	unordered_map<int, int> m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d", &x, &w);
			m.insert({ w, x });
		}
		else {
			scanf("%d", &w);
			printf("%d\n", m[w]);
		}
	}
}