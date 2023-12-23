#include<iostream>
#include<set>

using namespace std;

int main() {
	int deudPersonCount, boPersonCount;
	string personName;
	set<string> deudPerson;
	set<string> deudboPerson;

	cin >> deudPersonCount;
	cin >> boPersonCount;

	for (int i = 0; i < deudPersonCount; i++) {
		cin >> personName;
		deudPerson.insert(personName);
	}

	for (int i = 0; i < boPersonCount; i++) {
		cin >> personName;
		if (deudPerson.find(personName) != deudPerson.end()) {
			deudboPerson.insert(personName);
		}
	}

	cout << deudboPerson.size() << endl;

	for (string deudbojob : deudboPerson) {
		cout << deudbojob << endl;
	}
}