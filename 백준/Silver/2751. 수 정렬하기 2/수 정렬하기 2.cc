#include<stdio.h>
#include<set>
using namespace std;
int main() {
	int n;
	set<int> s;
	scanf("%d", &n);
	while (n-- != 0) {
		int d;
		scanf("%d", &d);
		s.insert(d);
	}
	for (int n : s) printf("%d\n", n);
}