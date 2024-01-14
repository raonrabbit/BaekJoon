#include<iostream>
#include<set>

using namespace std;

int main() {
	int peopleNum;
	string name;
	string behavior;
	set<string, greater<string>> record;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> peopleNum;

	for (int i = 0; i < peopleNum; i++) {
		cin >> name >> behavior;
		if (behavior == "enter") record.insert(name);
		else record.erase(name);
	}

	for (auto it = record.begin(); it != record.end(); it++) {
		cout << *it << '\n';
	}
}