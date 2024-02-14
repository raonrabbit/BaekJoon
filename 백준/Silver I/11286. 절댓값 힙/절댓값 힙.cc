#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
int main() {
	int n;
	int a;
	scanf("%d", &n);
	vector<int> r;
	map<int, int> s;
	map<int, int> ms;
	int b, c;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 0) {
			if (s.size() == 0 && ms.size() == 0) {
				r.push_back(0);
				continue;
			}
			if (s.size() == 0 && ms.size() != 0) {
				b = ms.begin()->first;
				r.push_back(b * -1);
				ms.begin()->second--;
				if (ms.begin()->second == 0) ms.erase(b);
				continue;
			}
			if (s.size() != 0 && ms.size() == 0) {
				b = s.begin()->first;
				r.push_back(b);
				s.begin()->second--;
				if (s.begin()->second == 0) s.erase(b);
				continue;
			}
			b = s.begin()->first;
			c = ms.begin()->first;
			if (c <= b) {
				r.push_back(c * -1);
				ms.begin()->second--;
				if (ms.begin()->second == 0) ms.erase(c);
			}
			else {
				r.push_back(b);
				s.begin()->second--;
				if (s.begin()->second == 0) s.erase(b);
			}
		}
		else {
			if (a > 0) {
				if (s.find(a) != s.end()) s[a]++;
				else s.insert({ a, 1 });
			}
			if(a < 0) {
				if (ms.find(a * -1) != ms.end()) ms[(a * -1)]++;
				else ms.insert({ (a * -1), 1 });
			}
		}
	}
	for (int i : r) printf("%d\n", i);
}