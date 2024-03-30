#include<stdio.h>
#include<set>
#include<queue>

using namespace std;

int main() {
	int n, t, result = -1;
	queue<int> q;
	set<int> set;

	scanf("%d", &n);
	q.push(n);
	set.insert(n);

	for (int i = 0; i < n; i++) {
		int qSize = q.size();
		for (int j = 0; j < qSize; j++) {
			int d = q.front();

			if (d == 1) {
				result = i;
				break;
			}
			if (d % 2 == 0 && set.find(d / 2) == set.end()) {
				set.insert(d / 2);
				q.push(d / 2);
			}

			if (d % 3 == 0 && set.find(d / 3) == set.end()) {
				set.insert(d / 3);
				q.push(d / 3);
			}

			if (set.find(d - 1) == set.end()) {
				set.insert(d - 1);
				q.push(d - 1);
			}

			q.pop();
		}

		if (result != -1) break;
	}

	printf("%d", result);
}