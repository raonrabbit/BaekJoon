#include<iostream>
#include<map>
#include<cmath>
using namespace std;

int main() {
	map<double, string> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double d;
		string name;
		cin >> d;
		cin >> name;
		while (m.find(d) != m.end()) d += 0.000001;
		m.insert({ d, name });
	}

	for (auto t = m.begin(); t != m.end(); t++) {
		cout << floor(t->first) << " " << t->second << "\n";
	}
}