#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
int main() {
	int n;
	unsigned int a;
	scanf("%d", &n);
	vector<unsigned int> r;
	map<unsigned int, int> s;
	int b;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 0) {
			if (s.size() == 0) r.push_back(0);
			else {
				b = s.begin()->first;
				r.push_back(b);
				s.begin()->second--;
				if(s.begin()->second == 0) s.erase(b);
			}
		}
		else {
			if (s.find(a) != s.end()) s[a]++;
			else s.insert({ a, 1 });
		}
	}
	for (unsigned int i : r) printf("%d\n", i);
}