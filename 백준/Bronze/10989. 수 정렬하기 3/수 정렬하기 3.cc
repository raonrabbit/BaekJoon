#include<map>
#include<stdio.h>
using namespace std;
int main() {
	int n, d;
	map<int, int> m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		if (m.find(d) == m.end()) m.insert({ d, 1 });
		else m[d]++;
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		for (int j = 0; j < i->second; j++) printf("%d\n", i->first);
	}
}