#include<stdio.h>
#include<set>

using namespace std;

int main() {
	int testcases;
	set<int> sejun;
	set<int> sebi;
	int sejunCount, sebiCount, temp;
	char result[100];

	scanf("%d", &testcases);

	for (int i = 0; i < testcases; i++) {
		scanf("%d%d", &sejunCount, &sebiCount);

		for (int i = 0; i < sejunCount; i++) {
			scanf("%d", &temp);
			sejun.insert(temp);
		}

		for (int i = 0; i < sebiCount; i++) {
			scanf("%d", &temp);
			sebi.insert(temp);
		}

		while (sejun.size() != 0 && sebi.size() != 0) {
			if (*sejun.begin() < *sebi.begin()) {
				sejun.erase(sejun.begin());
			}

			else {
				sebi.erase(sebi.begin());
			}
		}

		if (sejun.size() == 0) result[i] = 'B';
		else result[i] = 'S';

		sejun.clear();
		sebi.clear();
	}

	for (int i = 0; i < testcases; i++) {
		printf("%c\n", result[i]);
	}
}