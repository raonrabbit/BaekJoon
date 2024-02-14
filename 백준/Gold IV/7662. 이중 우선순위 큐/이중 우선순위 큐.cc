#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main() {
	vector<string> v;
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		char type;
		int n, data;
		bool isExsist;
		map<int, int> m;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf(" %c", &type);
			scanf("%d", &data);
			isExsist = m.find(data) != m.end();
			if (type == 'I') {
				if (isExsist) m[data]++;
				else m.insert({ data, 1 });
				continue;
			}

			if (type == 'D' && !m.empty()) {
				if (data == -1) {
					m.begin()->second--;
					if (m.begin()->second == 0) m.erase(m.begin());
				}
				else {
					auto k = --m.end();
					k->second--;
					if (k->second == 0) m.erase(k);
				}
				continue;
			}
		}
		if (m.empty()) v.push_back("EMPTY");
		else {
			auto k = --m.end();
			v.push_back(to_string(k->first) + " " + to_string(m.begin()->first));
		}
	}
	for (string s : v) cout << s << endl;
}