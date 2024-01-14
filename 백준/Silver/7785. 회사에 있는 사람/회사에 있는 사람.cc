#include<iostream>
#include<unordered_set>

using namespace std;

void merge(string* log, int first, int middle, int last) {
	string* sortedLog = new string[last - first + 1];
	int f = first;
	int m = middle + 1;
	int current = 0;
	while (f <= middle && m <= last) {
		if (log[f] > log[m]) sortedLog[current++] = log[f++];
		else sortedLog[current++] = log[m++];
	}

	if (middle < f) 
		while (m <= last) 
			sortedLog[current++] = log[m++];
	else 
		while (f <= middle) 
			sortedLog[current++] = log[f++];
	
	for (int i = first, j = 0; i <= last; i++, j++) {
		log[i] = sortedLog[j];
	}

	delete[] sortedLog;
}

void mergeSort(string *log, int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		mergeSort(log, first, middle);
		mergeSort(log, middle + 1, last);
		merge(log, first, middle, last);
	}
}

int main() {
	int peopleNum;
	string name;
	string behavior;
	unordered_set<string> record;
	string* log = new string[1000000];
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> peopleNum;

	for (int i = 0; i < peopleNum; i++) {
		cin >> name >> behavior;
		if (behavior == "enter") record.insert(name);
		else record.erase(name);
	}

	int count = 0;
	for (auto it = record.begin(); it != record.end(); it++) {
		log[count] = *it;
		count++;
	}
	mergeSort(log, 0, record.size() - 1);
	
	for (int i = 0; i < record.size(); i++) {
		cout << log[i] << '\n';
	}
}