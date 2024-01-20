#include<stdio.h>
#include<set>

using namespace std;

int main() {
	int N;
	int ticketNumber;
	set<int> fuckingSet;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &ticketNumber);
		fuckingSet.insert(ticketNumber);
	}

	int count = 1;
	while (true) {
		if (fuckingSet.find(count) == fuckingSet.end()) break;
		count++;
	}

	printf("%d", count);
}