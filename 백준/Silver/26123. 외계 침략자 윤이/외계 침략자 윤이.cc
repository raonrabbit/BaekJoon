#include<stdio.h>
#include<map>

using namespace std;

int main() {
	long N, D;
	map<long, long, greater<long>> m;
	scanf("%ld%ld", &N, &D);
	
	long n;
	for (int i = 0; i < N; i++) {
		scanf("%ld", &n);
		if (m.find(n) == m.end()) m.insert({ n, 1 });
		else m[n] += 1;
	}

	long result = 0;
	for (int i = 0; i < D; i++) {
		if (m.size() == 0) break;

		long boomCount;
		boomCount = m.begin()->second;
		result += boomCount;

		if (m.begin()->first - 1 != 0) {
			if (m.find(m.begin()->first - 1) != m.end()) {
				m[m.begin()->first - 1] += boomCount;
			}
			else {
				m.insert({ m.begin()->first - 1, boomCount });
			}
		}
		m.erase(m.begin()->first);
	}
	printf("%ld", result);
}